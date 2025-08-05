#pragma once
#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
    std::string target_;

public:
    RobotomyRequestForm(const std::string target_);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

protected:
	void doAction() const;
};