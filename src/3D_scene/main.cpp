// main.cpp
//
// This is the entry point for the 3D scene. It integrates the journal,
// questions, and minigames into the interactive environment.

#include <iostream>
#include "../journal/journalism.cpp"
#include "../questions/questions.cpp"

void show3DEnvironment() {
    std::cout << "Launching 3D environment...\n";
    // Placeholder for 3D rendering logic
}

int main() {
    const std::string journalFilePath = "journal_entries.txt";

    // Step 1: Handle journal entries
    handleJournalEntries(journalFilePath);

    // Step 2: Ask questions
    std::vector<Question> questions = getQuestions();
    std::string answers = askQuestions(questions);
    generatePetals(answers);

    // Step 3: Show 3D flower
    show3DEnvironment();

    // Step 4: Options
    std::cout << "What would you like to do next?\n";
    std::cout << "1. Play a minigame\n";
    std::cout << "2. Start over with a new flower\n";
    std::cout << "3. Look around at flowers you've created\n";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: std::cout << "Starting a minigame...\n"; break;
        case 2: main(); break; // Restart the program
        case 3: std::cout << "Viewing created flowers...\n"; break;
        default: std::cout << "Invalid choice. Exiting...\n"; break;
    }

    return 0;
}
