#pragma once
#include "AForm.hpp"
class ShrubberyCreationForm : ShrubberyCreationForm {
private:
    std::string target_;

public:
    ShrubberyCreationForm(const std::string target_);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

protected:
	void doAction();
}