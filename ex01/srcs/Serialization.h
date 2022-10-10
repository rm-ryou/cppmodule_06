#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <cstdlib>
#include <iostream>
#include <stdint.h>

struct Data
{
	int			num;
	std::string	str;
};

uintptr_t	serialize(Data* ptr);
Data*	deserialize(uintptr_t raw);

#endif // !SERIALIZATION_H