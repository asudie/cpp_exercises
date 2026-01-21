#include "BitcoinExchange.hpp"

void BitcoinExchange::start(char *filename){
    std::ifstream f;
    const char *data = "data.csv";
    f.open(filename);
    if(f.is_open()){
        parse(data);
        print_input(filename);
    } else{
        std::cout << "File doesn't exist!" << std::endl;
    }
}

time_t vali_date(std::string s1){
    struct tm tmStruct = {};
    const char *format = "%Y-%m-%d";
    if(strptime(s1.c_str(), format, &tmStruct) == NULL)
        return -1;
    return std::mktime(&tmStruct);
}

void BitcoinExchange::print_input(const char *filename){
    std::ifstream f;
    f.open(filename);
    for (std::string line; std::getline(f, line, '\n');) {
            if(line == "date | value")
                continue;
            std::stringstream ss(line);
            //std::cout << line << '\n';
            std::string tmp;
            std::string s1;
            std::string s2;
            getline(ss, tmp, '|');
            s1 = tmp.substr(0, tmp.size() - 1);
            getline(ss, s2, '\n');
            //std::cout << "S1 = [" << s1 << "], S2 = " << s2 << std::endl;
            float price = std::strtof(s2.c_str(), NULL);
            //std::cout << "Converted str to float " << price << std::endl;
            if(price < 0){
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            } else if( price > 1000){
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }

            time_t date = vali_date(s1);
            std::map<time_t,std::string>::iterator it = _data.find(date);
            if(it == _data.end()){
                std::map<time_t,std::string>::iterator low, prev;
                low = _data.lower_bound(date);
                if (low == _data.end()) {
                    it = _data.end();
                } else if (low == _data.begin()) {
                    it = _data.begin();
                } else {
                    prev = std::prev(low);
                    if ((date - prev->first) < (low->first - date))
                        it = low;
                    else
                        it = prev;
                }
            }
            if(date != -1){
                price *= std::strtof(it->second.c_str(), NULL);
                std::cout << s1 << " =>" << s2 << " = " << price << std::endl;
                //std::cout << date << std::endl;
            }
            else{
                std::cout << "Error: bad input => " << s1  << std::endl;

            }
        }
}

void BitcoinExchange::parse(const char *filename){
    std::ifstream f;
    char del = ',';
    f.open(filename);
    if(f.is_open()){
        for (std::string line; std::getline(f, line, '\n');) {
            if(line == "date,exchange_rate" || line == "date | value")
                continue;
            std::stringstream ss(line);
           // std::cout << line << '\n';
            std::string s1;
            std::string s2;
            getline(ss, s1, del);
            getline(ss, s2, '\n');
            //std::cout << "S1 = " << s1 << ", S2 = " << s2 << std::endl;
            _data.insert(std::make_pair(vali_date(s1), s2));
        }
        //for(std::map<time_t,std::string>::iterator it = _data.begin(); it != _data.end(); ++it)
           // std::cout << "[" << it->first << "]" << "[" << it->second << "]" << "\n";
    } else {
        std::cout << filename << " doesn't exist!" << std::endl;
    }
}