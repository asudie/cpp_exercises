#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target_) : AForm("PresidentialPardonForm", 25, 5), target_(target_){}
PresidentialPardonForm::~PresidentialPardonForm(){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), target_(other.target_){}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    if(this != &other)
    {
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return *this;
}
void PresidentialPardonForm::doAction() const {
     std::cout << target_ <<" has been pardoned by Zaphod Beeblebrox" << std::endl;
}
