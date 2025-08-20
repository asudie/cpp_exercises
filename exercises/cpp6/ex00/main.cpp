#include "ScalarConverter.hpp"

int main(){
	ScalarConverter::convert("'c'");
	std::cout << "------------------" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "------------------" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "------------------" << std::endl;
	std::cout << "------------------" << std::endl;
	ScalarConverter::convert("+inff");
	return 0;
}