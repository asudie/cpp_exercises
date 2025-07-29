#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string nickname;
    std::string darkestSecret;

public:
    Contact();

    void setFirstName(const std::string &value);
    void setLastName(const std::string &value);
    void setPhoneNumber(const std::string &value);
    void setNickname(const std::string &value);
    void setDarkestSecret(const std::string &value);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPhoneNumber() const;
    std::string getNickname() const;
    std::string getDarkestSecret() const;

    bool isEmpty() const;
};

class PhoneBook {
private:
    Contact contacts[8];
    int index;

public:
    PhoneBook() : index(0) {}
    void addContact();
    void searchContacts();
};

#endif // PHONEBOOK_H