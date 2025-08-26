#include "ScalarConverter.hpp"

int main(){
	ScalarConverter::convert("'c'");
	std::cout << "------------------" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "------------------" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "------------------" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "------------------" << std::endl;
	ScalarConverter::convert("234678");
	std::cout << "------------------" << std::endl;
	ScalarConverter::convert("2.095f");
	std::cout << "------------------" << std::endl;
	ScalarConverter::convert("54.452");
	return 0;
}