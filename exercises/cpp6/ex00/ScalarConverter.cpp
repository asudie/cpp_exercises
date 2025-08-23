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

static void printInt(const std::string &str){

}

static void printNormal(const std::string &str){
	char *end = NULL;
	errno = 0;
	long lval = std::strtol(str.c_str(), &end, 10);
	if(*end == '\0' && errno != ERANGE && lval >= INT_MIN && lval <= INT_MAX)
		// continue here
}

void ScalarConverter::convert(const std::string &str){
	if(isChar(str))
		return printChar(str[1]);
	if(isPseudo(str))
		return printPseudo(str);
	printNormal(str);
}

//////////////////////////////////////////////////////////////////
#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <climits>

static bool isCharLiteral(const std::string& s) {
    return s.size() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isPseudoLiteral(const std::string& s) {
    return (s == "nan" || s == "+inf" || s == "-inf" ||
            s == "nanf" || s == "+inff" || s == "-inff");
}

void ScalarConverter::convert(const std::string& literal) {
    // Handle char literal
    if (isCharLiteral(literal)) {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1)
                  << static_cast<double>(c) << std::endl;
        return;
    }

    // Handle pseudo literals
    if (isPseudoLiteral(literal)) {
        bool isFloat = literal.find('f') != std::string::npos;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (isFloat) {
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.size()-1) << std::endl;
        } else {
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
        return;
    }

    // Try conversion to int, float, double
    char* end = NULL;

    // --- Try int ---
    errno = 0;
    long lval = std::strtol(literal.c_str(), &end, 10);
    if (*end == '\0' && errno != ERANGE && lval >= INT_MIN && lval <= INT_MAX) {
        int val = static_cast<int>(lval);

        if (val >= 32 && val <= 126)
            std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << val << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << static_cast<float>(val) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1)
                  << static_cast<double>(val) << std::endl;
        return;
    }

    // --- Try float ---
    errno = 0;
    float fval = std::strtof(literal.c_str(), &end);
    if (*end == 'f' && *(end + 1) == '\0' && errno != ERANGE) {
        if (fval >= 32 && fval <= 126)
            std::cout << "char: '" << static_cast<char>(fval) << "'" << std::endl;
        else if (std::isnan(fval) || std::isinf(fval))
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (fval < INT_MIN || fval > INT_MAX || std::isnan(fval) || std::isinf(fval))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(fval) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << fval << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1)
                  << static_cast<double>(fval) << std::endl;
        return;
    }

    // --- Try double ---
    errno = 0;
    double dval = std::strtod(literal.c_str(), &end);
    if (*end == '\0' && errno != ERANGE) {
        if (dval >= 32 && dval <= 126)
            std::cout << "char: '" << static_cast<char>(dval) << "'" << std::endl;
        else if (std::isnan(dval) || std::isinf(dval))
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (dval < INT_MIN || dval > INT_MAX || std::isnan(dval) || std::isinf(dval))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(dval) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << static_cast<float>(dval) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1)
                  << dval << std::endl;
        return;
    }

    // If nothing matched
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

// Private stuff
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}
