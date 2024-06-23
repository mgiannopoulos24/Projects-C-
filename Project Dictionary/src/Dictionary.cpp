#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor
Dictionary::Dictionary(const std::string& filename) : filename(filename) {
    loadFromFile();
}

// Destructor
Dictionary::~Dictionary() {
    saveToFile();
}

void Dictionary::addWord(const std::string& word, const std::string& definition) {
    words[word] = definition;
    saveToFile();
    std::cout << "Word added successfully.\n";
}

bool Dictionary::removeWord(const std::string& word) {
    if (words.erase(word)) {
        saveToFile();
        std::cout << "Word removed successfully.\n";
        return true;
    } else {
        std::cout << "Word not found.\n";
        return false;
    }
}

std::string Dictionary::searchWord(const std::string& word) const {
    auto it = words.find(word);
    if (it != words.end()) {
        return it->second;
    } else {
        return "Word not found.";
    }
}

void Dictionary::listWords() const {
    if (words.empty()) {
        std::cout << "Dictionary is empty.\n";
    } else {
        for (const auto& pair : words) {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }
}

void Dictionary::loadFromFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file - '" << filename << "'\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word, definition;
        if (std::getline(iss, word, ':') && std::getline(iss, definition)) {
            words[word] = definition;
        }
    }

    file.close();
}

void Dictionary::saveToFile() const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file - '" << filename << "'\n";
        return;
    }

    for (const auto& pair : words) {
        file << pair.first << ":" << pair.second << "\n";
    }

    file.close();
}
