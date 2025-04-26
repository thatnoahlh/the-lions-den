#include "renderer.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Global variables for the rendering context
static GLFWwindow* window = nullptr;

void initializeOpenGL() {
    // Initialize GLFW
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    // Configure OpenGL context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window
    window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Print OpenGL version info
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL version supported: " << version << std::endl;
}

void beginFrame() {
    // Clear the screen and prepare for rendering
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void endFrame() {
    // Swap buffers and poll for events
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool shouldCloseWindow() {
    // Check if the window should close
    return glfwWindowShouldClose(window);
}

void renderModelWithTexture(unsigned int modelID, unsigned int textureID) {
    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Render the model (pseudo-code, actual implementation depends on your model and rendering logic)
    glBegin(GL_TRIANGLES);
    // Add vertex data here
    glEnd();
}

void showGUI() {
    // Render GUI components (e.g., ImGui if used)
    // Placeholder function
}

void cleanupRenderer() {
    // Clean up GLFW and other resources
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}