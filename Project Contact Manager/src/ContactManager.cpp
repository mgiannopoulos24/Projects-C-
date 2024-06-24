#include "ContactManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> // For std::setw

ContactManager::ContactManager() {
    // Load contacts from file during initialization
    loadContactsFromFile("contacts.txt");
}

void ContactManager::addContact(const Contact& contact) {
    contacts.push_back(contact);
}

void ContactManager::deleteContact(const std::string& name) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getName() == name) {
            contacts.erase(it);
            std::cout << "Contact deleted.\n";
            return;
        }
    }
    std::cout << "Contact not found.\n";
}

Contact* ContactManager::findContact(const std::string& name) {
    for (auto& contact : contacts) {
        if (contact.getName() == name) {
            return &contact;
        }
    }
    return nullptr;
}

void ContactManager::displayContacts() const {
    if (contacts.empty()) {
        std::cout << "No contacts to display.\n";
        return;
    }

    const int totalWidth = 80; // Total width of the table
    const int columnWidth = totalWidth / 3; // Each column gets 33.33% of the width

    std::string separatorLine(totalWidth+6, '-');
    std::cout << "---------------------------------------Contacts---------------------------------------\n";
    std::cout << "| " << std::left <<  std::setw(columnWidth) << "Name";
    std::cout << "| " << std::left <<  std::setw(columnWidth) << "Phone";
    std::cout << "| " << std::left <<  std::setw(columnWidth) << "Email" << " |\n";
    
    std::cout << separatorLine << "\n";
    for (const auto& contact : contacts) {
        std::cout << "| " << std::left <<  std::setw(columnWidth) << contact.getName();
        std::cout << "| " << std::left <<  std::setw(columnWidth) << contact.getPhone();
        std::cout << "| " << std::left <<  std::setw(columnWidth) << contact.getEmail() << " |\n";
    }
    std::cout << separatorLine << "\n";
}

void ContactManager::saveContactsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    for (const auto& contact : contacts) {
        file << contact.getName() << "," << contact.getPhone() << "," << contact.getEmail() << "\n";
    }

    file.close();
    if (file.fail()) {
        std::cerr << "Error writing to file: " << filename << "\n";
    } else {
        std::cout << "Contacts saved to " << filename << "\n";
    }
}

void ContactManager::loadContactsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    contacts.clear(); // Clear existing contacts

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, phone, email;
        if (std::getline(iss, name, ',') &&
            std::getline(iss, phone, ',') &&
            std::getline(iss, email)) {
            Contact newContact(name, phone, email);
            contacts.push_back(newContact);
        }
    }

    file.close();
    if (file.fail()) {
        std::cerr << "Error reading from file: " << filename << "\n";
    } else {
        std::cout << "Contacts loaded from " << filename << "\n";
    }
}
