#include "Contact.h"
#include <iostream>

Contact::Contact() {}

Contact::Contact(const std::string& name, const std::string& phone, const std::string& email)
    : name(name), phone(phone), email(email) {}

std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhone() const {
    return phone;
}

std::string Contact::getEmail() const {
    return email;
}

void Contact::setName(const std::string& name) {
    this->name = name;
}

void Contact::setPhone(const std::string& phone) {
    this->phone = phone;
}

void Contact::setEmail(const std::string& email) {
    this->email = email;
}

void Contact::display() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Phone: " << phone << "\n";
    std::cout << "Email: " << email << "\n";
}
