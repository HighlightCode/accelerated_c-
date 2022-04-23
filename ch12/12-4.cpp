#include "./src/Str_c.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
	Str_c str1 = "Aviation";
	Str_c str2 = "aviation";
	Str_c str3 = "Aviation";

	cout << str1 << " is equal to " << str2 << " ? " << (str1 == str2) << endl;
	cout << str2 << " is not equal to " << str3 << " ? " << (str2 != str3)
		 << endl;
	cout << str1 << " is equal to " << str3 << " ? " << (str1 == str3) << endl;

	return 0;
}