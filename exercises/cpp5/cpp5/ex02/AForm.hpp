#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class AForm{
protected:
	const std::string name_;
	bool signed_;
	const int sign_grade_;
	const int exec_grade_;

public:
	AForm(); 
	AForm(const std::string &name_, const int sign_grade_, const int exec_grade_);
	~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getSigned() const;

	void beSigned(Bureaucrat b);

	void execute(Bureaucrat const & executor) const;

	virtual void doAction() const = 0;

	class GradeTooHighException : public std::exception { 
	public:
		const char* what() const throw() {
			return "Grade_ is too high for this Form!";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade_ is too low for this Form!";
		}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);