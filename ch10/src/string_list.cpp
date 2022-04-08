#include <string>
#include "string_list.h"

using std::string;
using std::copy;

String_list::String_list() : str_list(new string[0]), length(0), max(1) {}

// copy constructor
String_list::String_list(const String_list& src) 
{
	length = src.length;
	max = src.max;
	str_list = new string[length];

	for (string::size_type sz_t = 0; sz_t < length; sz_t++)
		str_list[sz_t] = src.str_list[sz_t];
}

String_list::~String_list() 
{
	delete[] str_list;
}

void String_list::resize() 
{
	max *= 2;

	string* copy = new string[max];
	for(string::size_type sz_t = 0; sz_t < length; sz_t++) {
		copy[sz_t] = str_list[sz_t];
	}

	delete[] str_list;

	str_list = copy;
}

void String_list::push_back(string s)
{
	if (length + 1 >= max) 
		resize();

	length++;
	str_list[length - 1] = s;
}

string String_list::pop_back()
{
	string s = str_list[length];
	length--;

	return s;
}
