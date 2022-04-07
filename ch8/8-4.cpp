#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>

using std::vector; using std::cout;
using std::endl; using std::stringstream;
using std::string;

namespace ch8
{
template <class T> 
void swap( T& a, T& b )
{
  	T c(a); 
	a=b; 
	b=c;
}

template <class Bi>
void reverse(Bi begin, Bi end)
{
	while (begin != end) {
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}	
}

}

int main() {
	//vector<string> vec = {"abc", "def", "ghi", "jkl", "mno" , "pqr"};
	vector<int> vec = { 10, 15, 30, 105, 45, 70 };
	
  	// sorting the vector so the sorting step in the median functions won't affect performance
  	std::sort(vec.begin(), vec.end());
	ch8::reverse(vec.begin(), vec.end());
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, ", "));
	cout << endl;
}