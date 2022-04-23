#ifndef GUARD_STR_H
#define GUARD_STR_H

#include <algorithm>
#include <iostream>
#include <cstring>

#include "Vec.h"

class Str {

friend std::istream& operator>>(std::istream&, Str&);

public:
	typedef Vec<char>::size_type size_type;
	typedef Vec<char>::iterator iterator;
	typedef Vec<char>::const_iterator const_iterator;

	//default constructor
	Str() { };

	// create a Str containing n copies of n
	Str(size_type n, char c) : data(n,c) { };

	// create a Str fron null-terminated array of char
	Str(const char* p)	{
		std::copy(p, p + std::strlen(p), std::back_inserter(data));
	}

	// Need for 12-10.
	// create a Str from the range denoted by iterators b and e
	template<class In>
	Str(In b, In e) {
		std::copy(b , e ,std::back_inserter(data));
	}

	size_type size() const { return data.size(); }

	char& operator[](size_type i) {return data[i];}
	const char& operator[](size_type i) const { return data[i]; }

	Str& operator+=(const Str& s) {
		std::copy(s.begin(), s.end(), std::back_inserter(data));
		return *this;
	}

	template<class In>
	void insert(iterator position, In first, In end) { data.insert(position, first, end); }
	iterator begin() {return data.begin();}
	const_iterator begin() const { return data.begin(); }
	iterator end() {return data.end(); }
	const_iterator end() const { return data.end(); }

private:
	Vec<char> data;
};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

#endif