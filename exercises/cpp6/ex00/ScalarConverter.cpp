#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &other){}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
	return *this;
}

static bool isChar(const std::string &str){
	return str.size() == 3 && str[0] == '\'' && str[2] == '\'';
}

void ScalarConverter::convert(const std::string &str){
	if(isChar(str)){
		char c = str[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;

	}

}
