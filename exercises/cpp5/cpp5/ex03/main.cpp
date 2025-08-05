#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	try{
		Bureaucrat b1("John", 50);
		std::cout << b1 << std::endl;

		ShrubberyCreationForm sf1("my_target");

        b1.executeForm(sf1);
        
	}
	catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
	}
	try{
		Bureaucrat b1("John", 50);
		std::cout << b1 << std::endl;

		ShrubberyCreationForm sf1("my_target");

        b1.signForm(sf1);
		std::cout << sf1 << std::endl;
        b1.executeForm(sf1);

        Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;
		b2.executeForm(sf1);
        
	}
	catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
	}
	try{
		Bureaucrat b("Lilo", 40);
    RobotomyRequestForm form("Sonic");

    form.beSigned(b);
    b.executeForm(form);
	b.executeForm(form);
	b.executeForm(form);

	Bureaucrat c("Moanna", 72);
	c.executeForm(form);

	}
	catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
	}
	try{
		Bureaucrat b("Rob", 5);
    PresidentialPardonForm form("Sonic");

    form.beSigned(b);
    b.executeForm(form);

	Bureaucrat c("Moanna", 72);
	c.executeForm(form);

	}
	catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
	}
	return 0;
}