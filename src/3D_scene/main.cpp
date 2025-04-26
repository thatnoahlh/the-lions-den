//
// This is the entry point for the 3D scene. It integrates the journal,
// questions, and minigames into the interactive environment.

#include "../renderer/renderer.h"
#include "../loaders/modelLoader.h"
#include "../loaders/textureLoader.h"
#include <iostream>
#include <stdexcept>
#include <GL/glew.h>      // Include GLEW before any other OpenGL headers
#include <GLFW/glfw3.h>   // Include GLFW for window management
#include <glm/glm.hpp>                 // Core GLM functionality
#include <glm/gtc/matrix_transform.hpp> // For glm::lookAt, glm::perspective
#include <glm/gtc/type_ptr.hpp>         // For glm::value_ptr

// Global VAOs and texture IDs
unsigned int potVAO, stemVAO, petalVAO;
unsigned int potTextureID, stemTextureID, petalTextureID;

// Main application logic
void runApplication() {
    initializeOpenGL();

    // Load models
    std::vector<float> potVertexData, stemVertexData, petalVertexData;
    std::vector<unsigned int> potIndices, stemIndices, petalIndices;

    if (!loadModel("./assets/3D_models/pot.obj", potVertexData, potIndices)) {
        throw std::runtime_error("Failed to load pot model");
    }
    if (!loadModel("./assets/3D_models/stem.obj", stemVertexData, stemIndices)) {
        throw std::runtime_error("Failed to load stem model");
    }
    if (!loadModel("./assets/3D_models/petal.obj", petalVertexData, petalIndices)) {
        throw std::runtime_error("Failed to load petal model");
    }

    // Initialize VAOs
    potVAO = initializeModel(potVertexData, potIndices);
    stemVAO = initializeModel(stemVertexData, stemIndices);
    petalVAO = initializeModel(petalVertexData, petalIndices);

    // Load textures
    potTextureID = loadTexture("./assets/textures/pot_texture.png");
    stemTextureID = loadTexture("./assets/textures/stem_texture.png");
    petalTextureID = loadTexture("./assets/textures/petal_blue_texture.png");

    // Camera setup
    glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 5.0f),  // Camera position
        glm::vec3(0.0f, 0.0f, 0.0f),  // Look at the origin
        glm::vec3(0.0f, 1.0f, 0.0f)   // Up direction
    );
    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f),  // Field of view
        800.0f / 600.0f,      // Aspect ratio
        0.1f, 100.0f          // Near and far planes
    );

    // Lighting setup
    glm::vec3 lightPos(2.0f, 4.0f, -2.0f);
    glm::vec3 lightColor(1.0f, 1.0f, 1.0f);  // White light

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Disable face culling to render both front and back faces
    glDisable(GL_CULL_FACE);

    // Camera setup
    glm::vec3 cameraPos(0.0f, 0.0f, 5.0f); // Use this for viewPos

    // Main rendering loop
    int frameCount = 0;
    while (!shouldCloseWindow()) {
        beginFrame();
    
        useShaderProgram();
    
        // Set lighting uniforms
        setShaderUniform("lightPos", lightPos);       // Light position
        setShaderUniform("lightColor", lightColor);  // Light color
        setShaderUniform("viewPos", cameraPos);      // Camera position
    
        // Render each model
        glm::mat4 potModel = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f));
        renderModelWithTexture(potVAO, potTextureID, view, projection, lightPos, lightColor, potModel);
    
        glm::mat4 stemModel = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
        renderModelWithTexture(stemVAO, stemTextureID, view, projection, lightPos, lightColor, stemModel);
    
        glm::mat4 petalModel = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        renderModelWithTexture(petalVAO, petalTextureID, view, projection, lightPos, lightColor, petalModel);
    
        endFrame();
    }

    cleanupRenderer();
}

int main() {
    try {
        runApplication();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}