#include "Data.hpp"

Data::Data() : field1(12), field2(34.3){}
Data::~Data(){}
Data::Data(const Data &other){(void)other;}
Data &Data::operator=(const Data &other){
	(void)other;
	return *this;
}