#include "renderer.h"
#include <iostream>
#include <GL/glew.h>      // Modern OpenGL functions
#include <GLFW/glfw3.h>   // For window management
#include <glm/glm.hpp>    // Core GLM functionality
#include <glm/gtc/matrix_transform.hpp> // For glm::lookAt, glm::perspective
#include <glm/gtc/type_ptr.hpp>         // For glm::value_ptr
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vector>

static GLFWwindow* window = nullptr; // Global window variable
static unsigned int shaderProgram = 0; // Placeholder for shader program ID

// OpenGL Debug Callback
void GLAPIENTRY openglDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
    GLsizei length, const GLchar* message, const void* userParam) {
    std::cerr << "OpenGL Debug Message: " << message << std::endl;
}

// Initialize OpenGL settings
void initializeOpenGL() {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    window = glfwCreateWindow(800, 600, "OpenGL Application", NULL, NULL);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        throw std::runtime_error("Failed to initialize GLEW: " + std::string((char*)glewGetErrorString(err)));
    }

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    // Enable OpenGL debug output
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(openglDebugCallback, nullptr);

    initializeShaderProgram();
}

void beginFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void endFrame() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool shouldCloseWindow() {
    return glfwWindowShouldClose(window);
}

void showGUI() {
    // GUI rendering logic (e.g., ImGui) can be added here
}

void cleanupRenderer() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

// Function to initialize a model with vertex and index data
unsigned int initializeModel(const std::vector<float>& vertexData, const std::vector<unsigned int>& indices) {
    unsigned int VAO, VBO, EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), vertexData.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture coordinates
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Normals
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    return VAO;
}

void renderModelWithTexture(unsigned int modelID, unsigned int textureID, const glm::mat4& view, const glm::mat4& projection, const glm::vec3& lightPos, const glm::vec3& lightColor, const glm::mat4& model) {
    if (glIsVertexArray(modelID) == GL_FALSE) {
        std::cerr << "Error: Invalid VAO ID " << modelID << ". Skipping rendering." << std::endl;
        return;
    }

    glUseProgram(shaderProgram);

    setShaderUniform("model", model);
    setShaderUniform("view", view);
    setShaderUniform("projection", projection);
    setShaderUniform("lightPos", lightPos);
    setShaderUniform("lightColor", lightColor);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glBindVertexArray(modelID);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0); // Ensure the count matches your indices
    glBindVertexArray(0);
}

std::string loadShaderFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open shader file: " + filePath);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Helper function to compile a shader
unsigned int compileShader(const char* source, GLenum shaderType) {
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    // Check for compilation errors
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Error: Shader Compilation Failed\n" << infoLog << std::endl;
        throw std::runtime_error("Shader compilation failed");
    }

    return shader;
}

// Function to initialize the shader program
void initializeShaderProgram() {
    std::string vertexShaderSource = loadShaderFromFile("assets/shaders/vertex_shader.glsl");
    std::string fragmentShaderSource = loadShaderFromFile("assets/shaders/fragment_shader.glsl");

    unsigned int vertexShader = compileShader(vertexShaderSource.c_str(), GL_VERTEX_SHADER);
    unsigned int fragmentShader = compileShader(fragmentShaderSource.c_str(), GL_FRAGMENT_SHADER);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    int success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "Error: Shader Linking Failed\n" << infoLog << std::endl;
        throw std::runtime_error("Shader linking failed");
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    std::cout << "Shader program initialized successfully!" << std::endl;
}

void useShaderProgram() {
    if (shaderProgram == 0) {
        throw std::runtime_error("Shader program not initialized");
    }
    glUseProgram(shaderProgram);
}

void setShaderUniform(const char* name, const glm::mat4& matrix) {
    int location = glGetUniformLocation(shaderProgram, name);
    if (location != -1) {
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
}

void setShaderUniform(const char* name, const glm::vec3& vector) {
    int location = glGetUniformLocation(shaderProgram, name);
    if (location != -1) {
        glUniform3fv(location, 1, glm::value_ptr(vector));
    }
}

void drawModel(unsigned int modelID) {
    glBindVertexArray(modelID);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0); // Example: 36 indices
    glBindVertexArray(0);
}