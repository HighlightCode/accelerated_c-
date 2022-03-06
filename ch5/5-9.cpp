#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::vector; using std::cout;
using std::endl; using std::sort;
using std::ostream; using std::greater;
using std::string;

ostream& write_lower_output(ostream& os, const vector<string>& v)
{
	vector<string> v_copy = v;
	sort(v_copy.begin(), v_copy.end(), greater<string>());

	for (auto i : v_copy) {
		cout << i << endl;
	}

	return os;
}

int main()
{
	vector<string> words = { "TEST" , "test" , "mountain", "BIKE", "six", "seven", "EIGHT", "NINE", "ten" };
	write_lower_output(cout, words);
  
  	return 0;
}
