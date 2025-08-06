#pragma once

#include "AForm.hpp"

class Intern {
public:
    Intern(); 
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
    AForm *makeForm(std::string form, std::string target);
};