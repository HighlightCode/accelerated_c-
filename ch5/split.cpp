#include <vector>
#include <string>
#include <cctype>
#include "split.h"

using std::string; using std::vector;

vector<string> split(const string& s) 
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters [original value of i, i)
	while (i != s.size()) {
		while(i != s.size() && isspace(s[i])) 
			++i;

		// find the next word
		string_size j = i;
		while(j != s.size() && isspace(s[j]))
			++j;

		//if we found some nonwhitespace characters
		if (i != j) {
			//copy from s starting at i and taking j - i chars
			ret.push_back(s.substr(i, j-i));
			i = j;
		}
	}
	return ret;
}