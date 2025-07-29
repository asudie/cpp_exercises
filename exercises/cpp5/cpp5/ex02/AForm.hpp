#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class Form{
private:
	const std::string name_;
	bool signed_;
	const int sign_grade_;
	const int exec_grade_;

public:
	Form(); 
	Form(const std::string &name_, const int sign_grade_, const int exec_grade_);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;

	void beSigned(Bureaucrat b);

	class GradeTooHighException : public std::exception { 
	public:
		const char* what() const throw() {
			return "Grade_ is too high for this form!";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade_ is too low for this form!";
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Form &form);