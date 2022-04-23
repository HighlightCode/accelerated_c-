#include "Str.h"

#include <iostream>
using std::istream;
using std::ostream;

ostream &operator<<(ostream &os, const Str &s) {
	for (Str::size_type i = 0; i < s.size(); i++) {
		os << s[i];
	}
	return os;
}

istream &operator>>(istream &is, Str &s) {

	// obliterate existing values
	s.data.clear();
	// read and discard leading whitespace
	char c;
	while (is.get(c) && isspace(c));
	if(is) {
		do s.data.push_back(c);
		while (is.get(c) && !isspace(c));
		// if we read white space , then put it back on the stream
		if(is)
			is.unget();
	}
	return is;
}


Str operator+(const Str& lhs, const Str& rhs)
{
	Str r = lhs;
	r += rhs;
	return r;
}



