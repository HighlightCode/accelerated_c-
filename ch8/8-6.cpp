#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::string; using std::map;
using std::cin; using std::cout;
using std::vector; using std::pair;
using std::endl;

int main() {

	map<int,string> m = { {1, "hello"}, {2, "hello2"}};
	vector<pair<int,string> > x;

	copy(m.begin(), m.end(), back_inserter(x));
	for (size_t i = 0; i < x.size() ; i++) {
		cout << x[i].first << " " << x[i].second << endl;
	}
	cout << endl;
	// map doesnt support push_back function so back_inserter is an invalid operation
	// copy(x.begin(), x.end(), back_inserter(m));
	// you can choose inserter option, to insert map container

	cout << "map inserter test "<< endl;
	map<int,string> m2;
	copy(x.begin(), x.end(), std::inserter(m2, m2.end()));
	for (map<int,string>::iterator it = m2.begin(); it != m2.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}
}
