#include "ScalarConverter.hpp"

int main(){
	std::cout << "'c'" << "------------------" << std::endl;
	ScalarConverter::convert("'c'");
	std::cout << "+inf" << "------------------" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "nan" << "------------------" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "+inff" << "------------------" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "234678" << "------------------" << std::endl;
	ScalarConverter::convert("234678");
	std::cout << "2.095f" << "------------------" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << "54.452" << "------------------" << std::endl;
	ScalarConverter::convert("54.452");
	std::cout << "=-=" << "------------------" << std::endl;
	ScalarConverter::convert("=-=");
	return 0;
}