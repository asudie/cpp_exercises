#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
	try{
		Bureaucrat b1("John", 50);
		std::cout << b1 << std::endl;

		ShrubberyCreationForm sf1("my_target");

        b1.executeForm(sf1);
        b1.signForm(sf1);
        b1.executeForm(sf1);

        Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;
        
	}
	catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
	}

	/*try{
		Bureaucrat b1("John", 50);
		std::cout << b1 << std::endl;

		Form f1("F1", 51, 51);
		std::cout << f1 << std::endl;

		b1.signForm(f1);

		std::cout << f1 << std::endl;

		Form f2("F1", 49, 49);
		std::cout << f1 << std::endl;

		b1.signForm(f2);
	}
	catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
	}*/
	return 0;
}