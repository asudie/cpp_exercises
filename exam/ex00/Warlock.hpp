#pragma once

#include <iostream>
#include <string>

class Warlock {
private:
    std::string name;
    std::string title;

    // Disable copy constructor and assignment operator
    Warlock(const Warlock& other);
    Warlock& operator=(const Warlock& other);

public:
    // Constructor
    Warlock(const std::string& name, const std::string& title);

    // Destructor
    ~Warlock();

    // Getters
    const std::string& getName() const;
    const std::string& getTitle() const;

    // Setter
    void setTitle(const std::string& newTitle);

    // Introduce function
    void introduce() const;
};
