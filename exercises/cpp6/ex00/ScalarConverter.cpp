#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return *this;
}

static bool isChar(const std::string &str){
	return str.size() == 3 && str[0] == '\'' && str[2] == '\'';
}

static bool isPseudo(const std::string &str){
	return (str == "nan" || str == "+inf" || str == "-inf" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff");
}

static void printChar(char c){
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "f" << std::endl;

}

static void printPseudo(const std::string &str){
	bool isFloat = str.find('f') != std::string::npos;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if(isFloat){
			std::cout << "float: " << str << std::endl;
			if(str.find("ff") != std::string::npos)
				std::cout << "double: " << str.substr(0, str.size()-1) << std::endl;
			else
				std::cout << "double: " << str << std::endl;
		} else {
			std::cout << "float: " << str << "f" << std::endl;
			std::cout << "double: " << str << std::endl;
		}
		return;
}

void ScalarConverter::convert(const std::string &str){
	if(isChar(str))
		return printChar(str[1]);
	if(isPseudo(str))
		printPseudo(str);

}
