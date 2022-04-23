#include "./src/Str.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
	Vec<char> v;

	char data[] = {'h', 'e', 'l', 'l', 'o'};
	v.assign(data, data + sizeof(data));

	for (size_t i = 0; i < v.size(); i++)
		cout << v[i];

	cout << endl;

	return 0;
}