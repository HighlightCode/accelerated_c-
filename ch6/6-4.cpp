#include <iostream>
#include <ctime>
#include <vector>

using std::vector; using std::cout;
using std::endl;

int main() 
{
	vector<int> u(10000000, 100);

	double begin_copy = clock();
	vector<int> v(u);
	double end_copy = clock();

	vector<int> k;
	double begin_back = clock();
	copy(u.begin(), u.end(), back_inserter(k));
	double end_back = clock();

	// write the results
    cout << "direct initialization" << (end_copy - begin_copy) /
        CLOCKS_PER_SEC << " seconds for " << u.size() << " items." << endl;

    cout << "back_inserter took " << (end_back - begin_back) /
        CLOCKS_PER_SEC << " seconds for " << k.size() << " items." << endl;

	cout << "back_inserter took " << (end_back - begin_back) / 
		(end_copy - begin_copy) << " times slower than direct initialization." << endl;

	cout << endl;
    return 0;
}