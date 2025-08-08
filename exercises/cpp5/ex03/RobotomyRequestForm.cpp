#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target_) : AForm("RobotomyRequestForm", 72, 45), target_(target_){}
RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), target_(other.target_){}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if(this != &other)
    {
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return *this;
}
void RobotomyRequestForm::doAction() const {
    std::cout << "* LOUD DRILLING NOISE *" << std::endl;
    std::srand(std::time(NULL));
    if(std::rand() % 2 == 0)
        std::cout << "* " << target_ << "as been robotomized successfully *" << std::endl;
    else
        std::cout << "*  Robotomy on " << target_ << "has failed *" << std::endl;
}
