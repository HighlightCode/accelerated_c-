#include "Str_c.h"

#include <iostream>
using std::ostream;
using std::istream;

#include <iterator>
using std::ostream_iterator;

#include <algorithm>
using std::copy;

void Str_c::create(size_t n, char c) {
	d = new char[n + 1];
	length = n + 1;
	memset(d, c, n);
	d[n] = '\0';
}

Str_c& Str_c::operator=(const Str_c& rhs){
	//check for self assignment
	if(&rhs != this) {
		uncreate();
		create(rhs.d, rhs.d + rhs.size());
	}
	return *this;
}

void Str_c::append(const Str_c& s)
{
	append(s.data(), s.size());
}

void Str_c::append(const char* str, const size_t count) {
	size_t old_length = size();

	char *copy = new char[old_length];
	memcpy(copy, d, old_length);
	uncreate();

	length = old_length + count + 1;
	d = new char[length];
	memcpy(d, copy, old_length);
	memcpy(&d[old_length], str, count);
	d[length - 1] = '\0';

	delete[] copy;
}

void Str_c::prepend(const char *str, const size_t count) {
	size_t old_length = size();

	char *copy = new char[old_length];
	memcpy(copy, d, old_length);
	uncreate();
	
	length = old_length + count + 1;
	d = new char[length];
	memcpy(d, str, count);
	memcpy(&d[count], copy, old_length);
	d[length - 1] = '\0';
	
	delete[] copy;
}

void Str_c::append(const char c)
{
	append(&c, 1);
}

Str_c operator+(const Str_c& lhs , const Str_c& rhs)
{
	Str_c r = lhs;
  	r += rhs;
  	return r;
}

Str_c operator+(const Str_c& lhs, const char* str)
{
	Str_c r = lhs;
	r += str;
	return r;
}

Str_c operator+(const char* str, const Str_c& rhs)
{
	Str_c r = rhs;
	r += str;
	return r;
}

ostream& operator<<(ostream& os, const Str_c& s)
{
	copy(s.begin(), s.end(), ostream_iterator<char>(os));
	return os;
}

istream& operator>>(istream& is, Str_c& s)
{
	// oblicate existing values
	s.uncreate();
	s.create(0,'\0');

	//read and discard leading white space
	char c;
	while(is.get(c) && isspace(c));
	if( is ) {
		do s.append(c);
		while(is.get(c) && !isspace(c));

		// if we read whitespace , the put it back on the stream;
		if (is)
			is.unget();
	}
	return is;
}

size_t Str_c::copy_characters(char* dest, size_t count) const {
	size_t i;

	for (i = 0; i < count && i<size(); i++) {
		dest[i] = d[i];
	}

	return i;
}

istream& getline(istream& is, Str_c& s)
{
	// obliterate existing value
	s.uncreate();
	s.create(0,'\0');

	char c;

	if(is) {
		while(is.get(c) && c!= '\n')
			s.append(c);
	}

	return is;
}