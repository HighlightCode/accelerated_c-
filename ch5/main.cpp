#include <string>
#include <iostream>
#include <vector>
#include "frame.h"
#include "split.h"

using std::vector; using std::string;
using std::cin; using std::cout;
using std::endl;

int main() 
{
	vector<string> v1 = {"this is an","example","to","illustrate","framing"};
	vector<string> v2 = {"what is","essential","is","invisible","to the eye"};

	vector<string> vcat_string = vcat(frame(v1),frame(v2));
	vector<string> hcat_string = hcat(frame(v1),frame(v2));
	
	for(vector<string>::const_iterator iter = vcat_string.begin();
		iter != vcat_string.end(); iter++) {
			cout << *iter << endl;
	}

	cout << endl;
	
	for(vector<string>::const_iterator iter = hcat_string.begin();
		iter != hcat_string.end(); iter++) {
			cout << *iter << endl;
	}
}
