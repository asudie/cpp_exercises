#include "ScalarConverter.hpp"

int main(){
	ScalarConverter::convert("'c'");
	std::cout << "------------------" << std::endl;
	ScalarConverter::convert("+inf");
	return 0;
}