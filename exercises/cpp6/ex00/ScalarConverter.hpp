#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class ScalarConverter{
protected:
	ScalarConverter(); 
	
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

	static void convert(const char *str);	
};
