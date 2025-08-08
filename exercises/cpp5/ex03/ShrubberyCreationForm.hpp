#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string target_;

public:
    ShrubberyCreationForm(const std::string target_);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

protected:
	void doAction() const;
};