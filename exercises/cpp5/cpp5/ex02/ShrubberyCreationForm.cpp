#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target_) : AForm("ShrubberyCreationForm", 145, 137), target_(target_){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), target_(other.target_){}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if(this != &other)
    {
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return *this;
}
void ShrubberyCreationForm::doAction() const {
    std::ofstream file((target_ + "_shrubbery").c_str());
    if(!file)
        std::cerr << "Failed to open file" << std::endl;
    return;
    file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
    file.close();
}
