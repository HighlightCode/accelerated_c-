#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using std::cout; using std::vector;
using std::accumulate; using std::string;
using std::endl;

namespace ch6 {
	template<class InputIt, class T>
	constexpr
	T accumulate(InputIt first, InputIt last, T init) {
		for (; first != last; ++first) {
			init = std::move(init) + *first;
		}
		return init;
	}
}

string concat(const vector<string>& s)
{
	string out;
	return accumulate(s.begin(), s.end(), out);
}

int main()
{
	vector<string> v1 = {"this is an","example","to","illustrate","framing"};
	string s2 = concat(v1);
	string s3;
	s3 = ch6::accumulate(v1.begin(), v1.end(), s3);

	cout << s2 << endl;
	cout << s3 << endl;
	cout << endl;
}
