#ifndef STRING_LIST_H
#define STRING_LIST_H

#include <string>

class String_list
{
private:
	std::string* str_list;
	std::string::size_type length;
	std::string::size_type max;

public:
	typedef std::string* iterator;

	String_list();
	String_list(const String_list& rhs);
	~String_list();

	void push_back(std::string);
	void resize();
	std::string pop_back();
	size_t size() const {return length;}
	std::string* begin() const {return str_list; }
	std::string* end() const {return str_list + length; } 
};





#endif