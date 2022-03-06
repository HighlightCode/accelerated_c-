#include <iostream>
#include <vector>
#include <stdexcept>

using std::vector;
using std::cout;
using std::endl;
using std::cerr;


int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    // the code throws an error if we use v.begin()
	//copy(u.begin(), u.end(), v.begin());

	cout << endl;
    return 0;
}