#include <iostream>
#include <string>
#include <vector>

using std::string; using std::vector;
using std::cout; using std::ostream;
using std::endl;

bool is_palindrome(const string& s) {
	string::const_iterator iter = s.begin();
	string::const_reverse_iterator r_iter = s.rbegin();

	while(iter != r_iter.base() && iter + 1 != r_iter.base()) {
		if (tolower(*iter++) != tolower(*r_iter++))
			return false;
	}
	return true;
}

vector<string> get_palindrome(const vector<string>& v) {
	vector<string> p;
	vector<string>::const_iterator iter = v.begin();

	while(iter!=v.end()) {
		if(is_palindrome(*iter))
			p.push_back(*iter);
		++iter;
	}
	return p;	
}

ostream& write_palindrome(ostream& os, const vector<string>& v)
{
	vector<string> palindromes = get_palindrome(v);

	for(auto palindrome : palindromes)
		cout << palindrome << endl;
	
	return os;
}

int main()
{
	vector<string> words = { "TEST" , "teet" , "racecar", "BIKE", "six", "madam", "EIGHT", "reDder", "ten" };
	write_palindrome(cout, words);
}