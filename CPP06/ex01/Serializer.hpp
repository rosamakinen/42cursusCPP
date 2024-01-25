#pragma once

#include <cstdint>
#include <iostream>
#include "Data.hpp"

class Serializer
{

	private:
		Serializer();
		Serializer(const Serializer &another);
		Serializer &operator=(const Serializer &another);


	public:
		~Serializer();
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);

};