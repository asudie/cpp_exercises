#pragma once

class Data
{
private:
    int field1;
    double field2;
public:
    Data();
	~Data();
	Data(const Data &other);
	Data &operator=(const Data &other);

};