#include "PhoneBook.h"

Contact::Contact()
    : firstName(""), lastName(""), phoneNumber(""), nickname(""), darkestSecret("") {}

void Contact::setFirstName(const std::string &value) { firstName = value; }
void Contact::setLastName(const std::string &value) { lastName = value; }
void Contact::setPhoneNumber(const std::string &value) { phoneNumber = value; }
void Contact::setNickname(const std::string &value) { nickname = value; }
void Contact::setDarkestSecret(const std::string &value) { darkestSecret = value; }

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

bool Contact::isEmpty() const {
    return firstName.empty() && lastName.empty() && phoneNumber.empty()
           && nickname.empty() && darkestSecret.empty();
}
