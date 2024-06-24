#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
    std::string name;
    std::string phone;
    std::string email;
public:
    Contact();
    Contact(const std::string& name, const std::string& phone, const std::string& email);

    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    void setName(const std::string& name);
    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);

    void display() const;
};

#endif 
