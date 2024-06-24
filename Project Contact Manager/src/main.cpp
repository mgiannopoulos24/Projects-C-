#include <iostream>
#include <limits>
#include "Contact.h"
#include "ContactManager.h"

int main() {
    ContactManager manager;
    bool exitProgram = false;

    while (!exitProgram) {
        // Display menu
        std::cout << "\n===== Contact Management System =====\n";
        std::cout << "1. Add a contact\n";
        std::cout << "2. Delete a contact\n";
        std::cout << "3. Search for a contact\n";
        std::cout << "4. Display all contacts\n";
        std::cout << "5. Save contacts to file\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        // Handle invalid input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a number.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
            case 1: {
                std::string name, phone, email;

                std::cout << "Enter name: ";
                std::getline(std::cin, name);

                std::cout << "Enter phone number: ";
                std::getline(std::cin, phone);

                std::cout << "Enter email: ";
                std::getline(std::cin, email);

                // Create a new contact and add to manager
                Contact newContact(name, phone, email);
                manager.addContact(newContact);

                std::cout << "Contact added successfully.\n";
                break;
            }
            case 2: {
                std::string name;

                std::cout << "Enter name of contact to delete: ";
                std::getline(std::cin, name);

                manager.deleteContact(name);
                break;
            }
            case 3: {
                std::string name;

                std::cout << "Enter name of contact to search: ";
                std::getline(std::cin, name);

                Contact* found = manager.findContact(name);
                if (found) {
                    std::cout << "Contact found:\n";
                    found->display();
                } else {
                    std::cout << "Contact not found.\n";
                }
                break;
            }
            case 4: {
                manager.displayContacts();
                break;
            }
            case 5: {
                std::string filename;

                std::cout << "Enter filename to save contacts (e.g., contacts.txt): ";
                std::getline(std::cin, filename);

                manager.saveContactsToFile(filename);
                break;
            }
            case 6: {
                exitProgram = true;
                std::cout << "Exiting program.\n";
                break;
            }
            default:
                std::cerr << "Invalid choice. Please enter a number from 1 to 6.\n";
                break;
        }
    }

    return 0;
}
