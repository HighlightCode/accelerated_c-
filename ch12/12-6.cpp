#include "./src/Str_c.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
	Str_c name = "Geert";

	if (name)
		cout << "Hello " << name << "!" << endl;

	Str_c nickname;

	if (nickname)
		cout << "Hello " << nickname << "!" << endl;

	return 0;
}