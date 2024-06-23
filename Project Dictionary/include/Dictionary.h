#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <unordered_map>

class Dictionary {
public:
    // Constructor
    Dictionary(const std::string& filename);

    // Destructor
    ~Dictionary();

    // Add a word with its definition
    void addWord(const std::string& word, const std::string& definition);

    // Remove a word
    bool removeWord(const std::string& word);

    // Search for a word's definition
    std::string searchWord(const std::string& word) const;

    // List all words
    void listWords() const;

private:
    std::unordered_map<std::string, std::string> words;
    std::string filename;

    // Load words from file
    void loadFromFile();

    // Save words to file
    void saveToFile() const;
};

#endif // DICTIONARY_H
