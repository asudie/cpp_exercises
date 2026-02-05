#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <ctime>

class BitcoinExchange {
private:
    std::map<time_t, std::string> _data;
    // std::map<std::string, std::string> _input;
public:
    BitcoinExchange(){};
    ~BitcoinExchange(){};
    // add orthodox
    void start(char *filename);
    void parse(const char *filename);
    void print_input(const char *filename);
};
