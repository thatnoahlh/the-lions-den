#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <vector>
#include <string>

struct Question {
    std::string text;
    std::vector<std::string> choices;
};

std::vector<Question> getQuestions();
std::string askQuestions(const std::vector<Question>& questions);
void generatePetals(const std::string& answers);

#endif