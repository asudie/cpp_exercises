#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <climits>
#include <cerrno>
#include <cstdlib>
#include <cmath>

class ScalarConverter{
protected:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	
public:
	static void convert(const std::string &str);	
};
