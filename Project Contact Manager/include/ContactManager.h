#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "Contact.h"
#include <vector>
#include <string>

class ContactManager {
private:
    std::vector<Contact> contacts;

public:
    ContactManager(); // Constructor to load contacts from file

    void addContact(const Contact& contact);
    void deleteContact(const std::string& name);
    Contact* findContact(const std::string& name);
    void displayContacts() const;
    void saveContactsToFile(const std::string& filename) const;

private:
    void loadContactsFromFile(const std::string& filename);
};

#endif // CONTACTMANAGER_H
