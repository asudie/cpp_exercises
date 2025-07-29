#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat b1("John", 50);
		std::cout << b1 << std::endl;

		Bureaucrat b2("Alice", 1);
		std::cout << b2 << std::endl;

		Bureaucrat b3("Bob", 150);
		std::cout << b3 << std::endl;

		b1.incrementGrade();
		std::cout << "After increment: " << b1.getGrade() << std::endl;

		b2.incrementGrade();
		std::cout << "After increment: " << b2.getGrade() << std::endl;

		b3.decrementGrade();
		std::cout << "After increment: " << b3.getGrade() << std::endl;

		Bureaucrat invalid("Invalid", 0);
	}
	catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
	}

	try{
		Bureaucrat invalid2("Invalid2", 160);
	}
	catch (const std::exception &e){
		std::cerr << "Exeption: " << e.what() << std::endl;
	}
	return 0;
}