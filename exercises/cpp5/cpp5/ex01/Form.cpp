#include "Form.hpp"

Form::Form() : name_("Default"), signed_(0), sign_grade_(150), exec_grade_(150){}
Form::Form(const std::string &name_, const int sign_grade_, const int exec_grade_) : name_(name_), 
	signed_(0), sign_grade_(sign_grade_), exec_grade_(exec_grade_){
		if(sign_grade_ < 1 || exec_grade_ < 1)
		throw GradeTooHighException();
	else if(sign_grade_ > 150 || exec_grade_ > 150)
		throw GradeTooLowException();
	}
Form::~Form(){}
Form::Form(const Form &other) : name_(other.name_), signed_(other.signed_),
	sign_grade_(other.sign_grade_), exec_grade_(other.exec_grade_){}
Form &Form::operator=(const Form &other){
	if (this != &other) {
		this->signed_ = other.signed_;
	}
	return *this;
}

std::string Form::getName() const {return this->name_;}
int Form::getSignGrade() const {return this->sign_grade_;}
int Form::getExecGrade() const{return this->exec_grade_;}
bool Form::getSigned() const {return this->signed_;}

void Form::beSigned(Bureaucrat b){
	if(b.getGrade() <= this->sign_grade_)
	{
		this->signed_ = 1;
		std::cout << b.getName() << " signed " << this->name_ << std::endl;
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->name_  << " because his grade is too low"<< std::endl;
		throw GradeTooLowException();

	}
}
std::ostream &operator<<(std::ostream &out, const Form &form){
	out << form.getName() << ", sign grade " << form.getSignGrade() << ", exec grade " << form.getExecGrade() << ", signed = " << form.getSigned() << std::endl;
	return out;
}