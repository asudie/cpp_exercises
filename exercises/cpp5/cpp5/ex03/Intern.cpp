#include "Intern.hpp"


Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern &other){(void)other;}
Intern &Intern::operator=(const Intern &other){(void)other; return *this;}
static AForm* SFCreate(const std::string target){return new ShrubberyCreationForm(target);}
static AForm* PPCreate(const std::string target){return new PresidentialPardonForm(target);}
static AForm* RRCreate(const std::string target){return new RobotomyRequestForm(target);}
AForm* Intern::makeForm(std::string form, std::string target)
{
    Map forms[] = {
        {"shrabbery creation", &SFCreate},
        {"robotomy request", &RRCreate},
        {"presidential pardon", &PPCreate}
    };

    for(int i; i < 3; i++){
        if (forms[i].name == form)
        {
            std::cout << "Intern creates " << form << std::endl;
            return forms[i].create(target);
        }
    }
    std::cerr << "Error: form type '" << form << "' not recognized" << std::endl;
    return NULL;
}