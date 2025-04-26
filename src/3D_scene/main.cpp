// main.cpp
//
// This is the entry point for the 3D scene. It integrates the journal,
// questions, and minigames into the interactive environment.

#include <iostream>
#include "../journal/journalism.h"
#include "../questions/questions.h"
#include "../renderer/renderer.h"

// Function to manage the main application flow
void runApplication() {
    // Step 1: Handle journal entries
    const std::string journalFilePath = "journal_entries.txt";
    handleJournalEntries(journalFilePath);

    // Step 2: Ask questions
    std::vector<Question> questions = getQuestions();
    std::string answers = askQuestions(questions);
    generatePetals(answers);

    // Step 3: Initialize OpenGL and rendering environment
    initializeOpenGL();

    // Step 4: Load 3D models and textures
    std::cout << "Loading 3D assets...\n";
    loadModel("assets/3D_models/pot.obj");
    unsigned int potTexture = loadTexture("assets/textures/pot_texture.png");

    loadModel("assets/3D_models/stem.obj");
    unsigned int stemTexture = loadTexture("assets/textures/stem_texture.png");

    loadModel("assets/3D_models/petal.obj");

    // Associate textures with specific answers for petals
    std::map<char, unsigned int> petalTextures = {
        {'A', loadTexture("assets/textures/petal_red_texture.png")},
        {'B', loadTexture("assets/textures/petal_blue_texture.png")},
        {'C', loadTexture("assets/textures/petal_yellow_texture.png")},
        {'D', loadTexture("assets/textures/petal_pink_texture.png")}
    };

    // Step 5: Render the flower dynamically based on answers
    std::cout << "Rendering the 3D flower...\n";
    for (char answer : answers) {
        if (petalTextures.find(answer) != petalTextures.end()) {
            // Load and render petals with the appropriate texture
            unsigned int texture = petalTextures[answer];
            renderModelWithTexture("assets/3D_models/petal.obj", texture);
        }
    }

    // Render the pot and stem
    renderModelWithTexture("assets/3D_models/pot.obj", potTexture);
    renderModelWithTexture("assets/3D_models/stem.obj", stemTexture);

    // Step 6: Display the GUI for user interaction
    showGUI();
}

int main() {
    try {
        runApplication();
    } catch (const std::exception& ex) {
        std::cerr << "An error occurred: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
