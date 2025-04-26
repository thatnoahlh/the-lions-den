// main.cpp
//
// This is the entry point for the 3D scene. It integrates the journal,
// questions, and minigames into the interactive environment.

#include "../renderer/renderer.h"
#include "../loaders/modelLoader.h"
#include "../loaders/textureLoader.h"
#include <iostream>
#include <stdexcept>

// Function to run the main application
void runApplication() {
    // Initialize OpenGL and the rendering context
    initializeOpenGL();

    // Load models and textures
    unsigned int model1 = loadModel("path/to/model1.obj");
    unsigned int texture1 = loadTexture("path/to/texture1.png");

    unsigned int model2 = loadModel("path/to/model2.obj");
    unsigned int texture2 = loadTexture("path/to/texture2.png");

    // Main rendering loop
    while (!shouldCloseWindow()) {
        beginFrame(); // Clear and set up the frame

        // Render models with textures
        renderModelWithTexture(model1, texture1);
        renderModelWithTexture(model2, texture2);

        // Render GUI (if any)
        showGUI();

        endFrame(); // Swap buffers and poll events
    }

    // Clean up resources
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