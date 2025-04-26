// main.cpp
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

// Vertex and index data for models
std::vector<float> potVertexData = {
    // Add your pot vertex data here
};
std::vector<unsigned int> potIndices = {
    // Add your pot index data here
};

std::vector<float> stemVertexData = {
    // Add your stem vertex data here
};
std::vector<unsigned int> stemIndices = {
    // Add your stem index data here
};

std::vector<float> petalVertexData = {
    // Add your petal vertex data here
};
std::vector<unsigned int> petalIndices = {
    // Add your petal index data here
};

// Global VAOs and texture IDs
unsigned int potVAO, stemVAO, petalVAO;
unsigned int potTextureID, stemTextureID, petalTextureID;

// Main application logic
void runApplication() {
    initializeOpenGL();

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

    // Main rendering loop
    int frameCount = 0;
    while (!shouldCloseWindow()) {
        beginFrame();

        if (glIsVertexArray(potVAO) == GL_FALSE || glIsVertexArray(stemVAO) == GL_FALSE || glIsVertexArray(petalVAO) == GL_FALSE) {
            std::cerr << "Error: One or more VAOs are invalid. Exiting rendering loop." << std::endl;
            break;
        }

        // Render each model
        renderModelWithTexture(potVAO, potTextureID, view, projection, lightPos, lightColor);
        renderModelWithTexture(stemVAO, stemTextureID, view, projection, lightPos, lightColor);
        renderModelWithTexture(petalVAO, petalTextureID, view, projection, lightPos, lightColor);

        endFrame();

        frameCount++;
        if (frameCount > 4000) { // Avoid infinite loop for debugging purposes
            std::cerr << "Exceeded maximum frame count. Exiting rendering loop." << std::endl;
            break;
        }
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