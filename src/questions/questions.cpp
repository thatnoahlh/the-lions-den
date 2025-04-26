// questions.cpp
#include <iostream>
#include <vector>
#include <string>

struct Question {
    std::string text;
    std::vector<std::string> choices;
};

std::string askQuestions(const std::vector<Question>& questions) {
    std::string userAnswers;

    for (size_t i = 0; i < questions.size(); ++i) {
        std::cout << "Q" << (i + 1) << ": " << questions[i].text << "\n";
        for (size_t j = 0; j < questions[i].choices.size(); ++j) {
            std::cout << char('A' + j) << ". " << questions[i].choices[j] << "\n";
        }

        char answer;
        std::cout << "Your answer (A/B/C/D): ";
        std::cin >> answer;

        // Validate input
        if (answer >= 'A' && answer <= 'D') {
            userAnswers += answer;
        } else {
            std::cerr << "Invalid answer. Skipping question.\n";
            userAnswers += ' ';
        }
    }

    return userAnswers;
}

void generatePetals(const std::string& answers) {
    for (char answer : answers) {
        switch (answer) {
            case 'A': std::cout << "Generated a red petal.\n"; break;
            case 'B': std::cout << "Generated a blue petal.\n"; break;
            case 'C': std::cout << "Generated a yellow petal.\n"; break;
            case 'D': std::cout << "Generated a pink petal.\n"; break;
            default: std::cout << "No petal generated for invalid input.\n"; break;
        }
    }
}
