#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(); 
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
    void decrementGrade();

	void signForm(Form &form);

	void executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Bureaucrat's grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Bureaucrat's grade is too low!";
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);