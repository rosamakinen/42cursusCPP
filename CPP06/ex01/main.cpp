#include "Serializer.hpp"

int main(void) 
{
	Data theData;
	theData.i = 42;
	
	uintptr_t serializedData;
	Data* deserializedData;
	
	std::cout << "original value as reference " << theData.i << std::endl;
	std::cout << "original address " << &theData << std::endl;

	serializedData = Serializer::serialize(&theData);
	std::cout << "serialized address " << &serializedData << std::endl;
	
	deserializedData = Serializer::deserialize(serializedData);
	std::cout << "deserialized address: " << deserializedData << std::endl;
	std::cout << "deserialized value: " << deserializedData->i << std::endl;

	return (0);
}