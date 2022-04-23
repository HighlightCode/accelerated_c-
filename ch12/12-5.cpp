#include "./src/Str_c.h"

#include <iostream>
using std::cout;
using std::endl;


int main() {
	Str_c name = "Geert";
	Str_c greeting = "Hello, " + name;

	cout << greeting << endl;

	Str_c goodbye = name + ", bye!";

	cout << goodbye << endl;

	Str_c complete = "Hello, " + name + " and goodbye!";

	cout << complete << endl;

	return 0;
}