#include "AForm.hpp"

AForm::AForm() : name_("Default"), signed_(0), sign_grade_(150), exec_grade_(150){}
AForm::AForm(const std::string &name_, const int sign_grade_, const int exec_grade_) : name_(name_), 
	signed_(0), sign_grade_(sign_grade_), exec_grade_(exec_grade_){
		if(sign_grade_ < 1 || exec_grade_ < 1)
		throw GradeTooHighException();
	else if(sign_grade_ > 150 || exec_grade_ > 150)
		throw GradeTooLowException();
	}
AForm::~AForm() {}
AForm::AForm(const AForm &other) : name_(other.name_), signed_(other.signed_),
	sign_grade_(other.sign_grade_), exec_grade_(other.exec_grade_){}
AForm &AForm::operator=(const AForm &other){
	if (this != &other) {
		this->signed_ = other.signed_;
	}
	return *this;
}

std::string AForm::getName() const {return this->name_;}
int AForm::getSignGrade() const {return this->sign_grade_;}
int AForm::getExecGrade() const{return this->exec_grade_;}
bool AForm::getSigned() const {return this->signed_;}

void AForm::execute(Bureaucrat const & executor) const{
	if(this->signed_ && executor.getGrade() <= this->exec_grade_)
	{
		this->doAction();
	}
	else
	{
		std::cout << executor.getName() << " couldn't execute " << this->name_  << " because his grade is too low or the AForm isn't signed." << std::endl;
		throw GradeTooLowException();
	}

}

void AForm::beSigned(Bureaucrat b){
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
std::ostream &operator<<(std::ostream &out, const AForm &AForm){
	out << AForm.getName() << ", sign grade " << AForm.getSignGrade() << ", exec grade " << AForm.getExecGrade() << ", signed = " << AForm.getSigned() << std::endl;
	return out;
}