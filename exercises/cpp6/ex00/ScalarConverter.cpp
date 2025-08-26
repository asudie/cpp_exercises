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

static void printInt(long lval){
    int val = static_cast<int>(lval);
    if(val >= 32 && val <= 126)
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    else   
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << val << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

static void printFloat(float val){
    if(val >= 32 && val <= 126)
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    else if(std::isnan(val) || std::isinf(val))
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if(val < INT_MIN || val > INT_MAX || std::isnan(val) || std::isinf(val))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << val << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
    return;
}

static void printDouble(double val){
    if(val >= 32 && val <= 126)
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    else if(std::isnan(val) || std::isinf(val))
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if(val < INT_MIN || val > INT_MAX || std::isnan(val) || std::isinf(val))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
    return;
}

static void printNormal(const std::string &str){
	char *end = NULL;
	errno = 0;
	long lval = std::strtol(str.c_str(), &end, 10);
	if(*end == '\0' && errno != ERANGE && lval >= INT_MIN && lval <= INT_MAX)
        return printInt(lval);
    errno = 0;
    float fval = std::strtof(str.c_str(), &end);
    if(*end == 'f' && *(end + 1) == '\0' && errno != ERANGE){
        return printFloat(fval);
	}
	errno = 0;
    double dval = std::strtod(str.c_str(), &end);
	if(*end == '\0' && errno != ERANGE)
		return printDouble(dval);
	
}

void ScalarConverter::convert(const std::string &str){
	if(isChar(str))
		return printChar(str[1]);
	if(isPseudo(str))
		return printPseudo(str);
	printNormal(str);
}

//////////////////////////////////////////////////////////////////

