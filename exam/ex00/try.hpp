#pragma once

#include <string>
#include <iostream>

class Warlock{
private:
    std::string name;
    std::string title;
    Warlock(const Warlock& other);
    operator=(const Warlock& other);

public:
    Warlock(std::string name, std::string title);
    ~Warlock();
    const std::string getName&() const;
    const std::string getTitle&() const;
    void setTitle(const std::string& newTitle);
    void introduce() const;
};