#include "PhoneBook.h"

std::string formatField(const std::string &field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return std::string(10 - field.length(), ' ') + field;
}

void PhoneBook::addContact() {
    if (this->index == 8)
        this->index = 0;

    Contact &c = this->contacts[this->index];
    std::string input;
    
    do {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
    } while (input.empty());
    c.setFirstName(input);

    do {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
    } while (input.empty());
    c.setLastName(input);

    do {
        std::cout << "Enter Phone Number (+): ";
        std::getline(std::cin, input);
    } while (input.empty() || input[0] != '+');
    c.setPhoneNumber(input);

    do {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
    } while (input.empty());
    c.setNickname(input);

    do {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
    } while (input.empty());
    c.setDarkestSecret(input);

    this->index++;
    std::cout << "Contact added successfully." << std::endl;
}

void PhoneBook::searchContacts() {
    if (this->index == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < 8; ++i) {
        if (contacts[i].isEmpty())
            continue;
        std::cout << std::setw(10) << i << "|"
                  << formatField(contacts[i].getFirstName()) << "|"
                  << formatField(contacts[i].getLastName()) << "|"
                  << formatField(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter the index of the contact to view details: ";
    std::string input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    std::stringstream ss(input);
    int idx;
    if (!(ss >> idx) || idx < 0 || idx >= 8 || contacts[idx].isEmpty()) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    const Contact &c = contacts[idx];
    std::cout << "First Name:     " << c.getFirstName() << std::endl;
    std::cout << "Last Name:      " << c.getLastName() << std::endl;
    std::cout << "Phone Number:   " << c.getPhoneNumber() << std::endl;
    std::cout << "Nickname:       " << c.getNickname() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}
