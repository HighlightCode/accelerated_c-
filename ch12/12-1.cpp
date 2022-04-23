#include "./src/Str_c.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	Str_c s("hello");  // construct s
	Str_c t = "hello"; // initialize t
	s = "hello";	 // assign a new value to s
	Str_c s1 = "test";
	Str_c s2 = "ing";

	cout << "Enter a string: ";
	cin >> s;		   // use the input operator to read a string
	cout << s << endl; // use the output operator to write a string
	s[3];			   // use the index operator to access a character
	s1 + s2;		   // use the addition operator to concatenate two strings

	Str_c name = "Accelerated C++";
	Str_c greeting = "Hello, " + name + " !";
	cout << greeting << endl;

	Str_c temp1("Hello, ");	 // Str_c::Str_c(const char*)
	Str_c temp2 = temp1 + name; // operator*(const Str_c&, const Str_c&)
	Str_c temp3("!");			  // Str_c::Str_c(const char*)
	greeting = temp2 + temp3; // operator*(const Str_c&, const Str_c&)

	return 0;
}