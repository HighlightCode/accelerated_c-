#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "./src/string_list.h"

using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::sort;
using std::string;

bool space(char c) {
	return isspace(c) != 0;
}

bool not_space(char c) {
	return !isspace(c);
}

String_list split(const string &str) {
	typedef string::const_iterator iter;
	String_list let;

	iter i = str.begin();
	while (i != str.end()) {
		i = find_if(i, str.end(), not_space);

		iter j = find_if(i, str.end(), space);

		if (i != str.end())
			let.push_back(string(i, j));
		i = j;
	}
	return let;
}

int main() {
	string str = "Please split this amazing string!";
	String_list str_l = split(str);
	String_list::iterator iter = str_l.begin();

	while (iter != str_l.end())
		cout << *iter++ << endl;

	return 0;
}