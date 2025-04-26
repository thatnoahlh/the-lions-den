// journal.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct JournalEntry {
    std::string date;
    std::string title;
    std::string content;
};

void displayPreviousEntries(const std::vector<JournalEntry>& entries) {
    std::cout << "Previous Journal Entries:\n";
    for (const auto& entry : entries) {
        std::cout << "[" << entry.date << "] " << entry.title << "\n";
    }
}

void createNewEntry(std::vector<JournalEntry>& entries, const std::string& filePath) {
    JournalEntry newEntry;
    std::cout << "Enter the date (YYYY-MM-DD): ";
    std::cin >> newEntry.date;

    std::cin.ignore(); // Clear the newline character from the input buffer
    std::cout << "Enter the title: ";
    std::getline(std::cin, newEntry.title);

    std::cout << "Enter your journal entry (end with a blank line):\n";
    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        newEntry.content += line + "\n";
    }

    entries.push_back(newEntry);

    // Append the new entry to the file
    std::ofstream outFile(filePath, std::ios::app);
    if (outFile.is_open()) {
        outFile << newEntry.date << "\n" << newEntry.title << "\n" << newEntry.content << "----\n";
        outFile.close();
    } else {
        std::cerr << "Error: Unable to save the journal entry.\n";
    }

    std::cout << "Your entry has been saved, and the flower's stem grows taller!\n";
}

void handleJournalEntries(const std::string& filePath) {
    std::vector<JournalEntry> entries;
    std::ifstream inFile(filePath);

    if (inFile.is_open()) {
        std::string line, date, title, content;
        while (std::getline(inFile, line)) {
            if (line == "----") {
                entries.push_back({date, title, content});
                date.clear();
                title.clear();
                content.clear();
            } else if (date.empty()) {
                date = line;
            } else if (title.empty()) {
                title = line;
            } else {
                content += line + "\n";
            }
        }
        inFile.close();
    }

    if (!entries.empty()) {
        std::cout << "Would you like to view previous entries or create a new one? (view/new): ";
        std::string choice;
        std::cin >> choice;

        if (choice == "view") {
            displayPreviousEntries(entries);
        } else if (choice == "new") {
            createNewEntry(entries, filePath);
        } else {
            std::cerr << "Invalid choice. Exiting journal module.\n";
        }
    } else {
        std::cout << "No previous entries found. Creating a new entry...\n";
        createNewEntry(entries, filePath);
    }
}
