#include <string>
#include <iostream>
#include <vector>
#include "frame.h"
#include "split.h"

using std::vector; using std::string;
using std::cin; using std::cout;
using std::endl;

vector<string> center(const vector<string>& v)
{
	vector<string> v_out;
	vector<string>::size_type maxlen = width(v);

	string border(maxlen+2,'*');
	v_out.push_back(border);
	for(vector<string>::const_iterator iter=v.begin(); iter!=v.end(); iter++) {
		int left_spaces = (maxlen - (*iter).size()) / 2;
		int right_spaces = maxlen - (*iter).size() - left_spaces;
		v_out.push_back("*" + string(left_spaces,' ') + *iter + 
			string(right_spaces,' ') + "*");
	}
	v_out.push_back(border);
	return v_out;
}

int main() 
{
	vector<string> v1 = {"this is an","example","to","illustrate","framing"};
	vector<string> centered_v = center(v1);

	vector<string>::const_iterator iter = centered_v.begin();

	while (iter != centered_v.end())
		cout << *iter++ << endl;
	return 0;
}