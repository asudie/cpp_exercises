#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <ctime>

class BitcoinExchange {
private:
    std::map<time_t, std::string> _data;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
    
    void start(char *filename);
    void parse(const char *filename);
    void print_input(const char *filename);
};
