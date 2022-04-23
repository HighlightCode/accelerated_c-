#include "./src/Str_c.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
	Str_c input;

	while (getline(std::cin, input))
		cout << input << endl;

	return 0;
}