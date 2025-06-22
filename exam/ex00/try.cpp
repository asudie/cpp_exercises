#include "try.hpp"

Warlock(std::string name, std::string title) : name(name), type(type) {
    std::cout << name << ": This looks like another boring day." << std::endl;
}

~Warlock(){
    std::cout << name << ": My job here is done!" << std::endl;
}

const std::string getName&() const {
    return this->name;
}

const std::string getTitle&() const {
    return this->title;
}

void setTitle(const std::string& newTitle){
    this->title = newTitle;
}

void introduce() const{
    std::cout << name << ": I am" << name << ", " << title << std::endl;
}