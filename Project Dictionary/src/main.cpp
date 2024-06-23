#include <iostream>
#include "Dictionary.h"

void displayMenu() {
    std::cout << "Dictionary App\n";
    std::cout << "==============\n";
    std::cout << "1. Add word\n";
    std::cout << "2. Remove word\n";
    std::cout << "3. Search word\n";
    std::cout << "4. List all words\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Dictionary dictionary("Dictionary.txt");
    int choice;
    std::string word, definition;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter word: ";
                std::cin >> word;
                std::cin.ignore();
                std::cout << "Enter definition: ";
                std::getline(std::cin, definition);
                dictionary.addWord(word, definition);
                break;
            case 2:
                std::cout << "Enter word to remove: ";
                std::cin >> word;
                dictionary.removeWord(word);
                break;
            case 3:
                std::cout << "Enter word to search: ";
                std::cin >> word;
                std::cout << dictionary.searchWord(word) << "\n";
                break;
            case 4:
                dictionary.listWords();
                break;
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
