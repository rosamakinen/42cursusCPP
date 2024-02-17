#pragma once

#include <string>

template <typename T>
void iter(T* array, int length, void (*function)(T&))
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}