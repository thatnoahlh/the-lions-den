// main.cpp
//
// This is the entry point for the 3D scene. It integrates the journal,
// questions, and minigames into the interactive environment.

#include "../renderer/renderer.h"
#include "../loaders/modelLoader.h"
#include "../loaders/textureLoader.h"
#include <iostream>
#include <stdexcept>

void runApplication() {
    initializeOpenGL();

    // Load models
    unsigned int potModel = loadModel("./assets/3D_models/pot.obj");
    unsigned int stemModel = loadModel("./assets/3D_models/stem.obj");
    unsigned int petalModel = loadModel("./assets/3D_models/petal.obj");

    // Load textures
    unsigned int potTexture = loadTexture("./assets/textures/pot_texture.png");
    unsigned int stemTexture = loadTexture("./assets/textures/stem_texture.png");
    unsigned int petalBlueTexture = loadTexture("./assets/textures/petal_blue_texture.png");
    unsigned int petalPinkTexture = loadTexture("./assets/textures/petal_pink_texture.png");
    unsigned int petalRedTexture = loadTexture("./assets/textures/petal_red_texture.png");
    unsigned int petalYellowTexture = loadTexture("./assets/textures/petal_yellow_texture.png");

    // Main rendering loop
    while (!shouldCloseWindow()) {
        beginFrame();

        // Render the pot
        renderModelWithTexture(potModel, potTexture);

        // Render the stem
        renderModelWithTexture(stemModel, stemTexture);

        // Render petals with different textures
        renderModelWithTexture(petalModel, petalBlueTexture);
        renderModelWithTexture(petalModel, petalPinkTexture);
        renderModelWithTexture(petalModel, petalRedTexture);
        renderModelWithTexture(petalModel, petalYellowTexture);

        showGUI();
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