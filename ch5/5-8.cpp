#include <vector>
#include <cstring>
#include <iostream>
#include "frame.h"

using std::vector; using std::cout;
using std::endl; using std::string;

vector<string> hcat_remake(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	string::size_type width1 = width(left) + 1;

	vector<string>::size_type i = 0, j = 0;

	string s;
	while(i != left.size() || j != right.size()){

		if(i != left.size())
			s = left[i++];

		s += string(width1 - s.size(),' ');

		if(j != right.size())
			s += right[j++];

		ret.push_back(s);
	}
	
	return ret; 
	
}

int main() 
{
	vector<string> v1 = {"this is an","example","to","illustrate","framing"};
	vector<string> v2 = {"what is","essential","is","invisible","to the eye"};

	vector<string> hcat_string = hcat_remake(frame(v1),frame(v2));
	
	for(vector<string>::const_iterator iter = hcat_string.begin();
		iter != hcat_string.end(); iter++) {
			cout << *iter << endl;
	}
}
