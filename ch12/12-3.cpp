#include "./src/Str_c.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
	Str_c short_str = "audio";
	Str_c default_str1 = "Aviation";
	Str_c default_str2 = "aviation";
	Str_c long_str = "aviation industry";

	cout << short_str << " is smaller than " << default_str2 << " ? "
		 << (short_str < default_str2) << endl;
	cout << long_str << " is smaller or equal to " << default_str2 << " ? "
		 << (long_str <= default_str2) << endl;
	cout << short_str << " is bigger than " << long_str << " ? "
		 << (short_str > long_str) << endl;
	cout << long_str << " is bigger or equal to " << long_str << " ? "
		 << (long_str >= long_str) << endl;

	return 0;
}