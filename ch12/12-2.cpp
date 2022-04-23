#include "./src/Str_c.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
	Str_c str = "Accelerated C++";
	const char *data = str.data();

	for (size_t i = 0; i < str.size(); i++)
		cout << data[i];
	cout << endl;

	const char *c = str.c_str();

	cout << c << endl;

	char copied[8];
	str.copy(copied, sizeof(copied));

	for (size_t i = 0; i < sizeof(copied); i++)
		cout << copied[i];
	cout << endl;

	return 0;
}