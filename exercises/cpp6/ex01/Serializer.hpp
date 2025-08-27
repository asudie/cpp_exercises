#pragma once

#include "Data.hpp"
#include <cstdint>
class Serializer
{
protected:
    Serializer();
	~Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);

public:
    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};