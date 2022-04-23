#include "./src/Str.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main() {
	string greeting = "Hello buddy, how are you doing?";

	Str str(greeting.begin(), greeting.end());
	cout << str << endl;

	return 0;
}