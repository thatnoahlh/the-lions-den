// questions.cpp
#include "questions.h"
#include <iostream>

std::vector<Question> getQuestions() {
    return {
        {"What helps you relax?", {"Meditation", "Exercise", "Reading", "Music"}},
        {"What is your favorite color?", {"Red", "Blue", "Yellow", "Pink"}},
        {"What time of day do you feel most energized?", {"Morning", "Afternoon", "Evening", "Night"}},
        {"What is your favorite hobby?", {"Painting", "Gaming", "Cooking", "Gardening"}},
        {"What is your go-to comfort food?", {"Pizza", "Ice Cream", "Pasta", "Salad"}},
        {"What type of music do you prefer?", {"Classical", "Pop", "Rock", "Jazz"}},
        {"What is your favorite season?", {"Spring", "Summer", "Autumn", "Winter"}},
        {"What motivates you the most?", {"Goals", "Family", "Friends", "Challenges"}},
        {"What do you do to unwind?", {"Watch TV", "Take a Walk", "Read", "Meditate"}},
        {"What is your dream vacation?", {"Beach", "Mountains", "City", "Countryside"}}
    };
}

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