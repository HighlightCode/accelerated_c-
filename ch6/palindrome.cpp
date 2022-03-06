#include <cctype>
#include <iostream>
#include <string>

using std::string; using std::cin;
using std::cout; using std::endl;

namespace accelerated_6{
	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))   
				return false;
		++first1; ++first2;
		}
		return true;
	}
}

bool is_palindrome(const string& s) {
	return accelerated_6::equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
	string s;
	while (cin >> s) {
		if (is_palindrome(s))
            cout << s << " is a palindrome" << endl;
        else
            cout << s << " is not a palindrome" << endl;
	}

	cout << endl;
	return 0;
}
