#include <iostream>
#include <iterator>
#include <string>

#include "./src/split.h"

using std::cin; using std::cout;
using std::getline; using std::ostream_iterator;
using std::string;

int main() {
	
	string s;
	while(getline(cin, s))
		split(s, ostream_iterator<string>(cout, "\n"));
	return 0;
}