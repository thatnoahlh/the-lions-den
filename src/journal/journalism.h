#ifndef JOURNALISM_H
#define JOURNALISM_H

#include <string>
#include <vector>

struct JournalEntry {
    std::string date;
    std::string title;
    std::string content;
};

void displayPreviousEntries(const std::vector<JournalEntry>& entries);
void createNewEntry(std::vector<JournalEntry>& entries, const std::string& filePath);
void handleJournalEntries(const std::string& filePath);

#endif