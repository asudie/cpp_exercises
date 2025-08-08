#pragma once
#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm {
private:
    std::string target_;

public:
    PresidentialPardonForm(const std::string target_);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

protected:
	void doAction() const;
};