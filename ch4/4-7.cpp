#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;

int main() 
{

	vector<double> doubles;
	double t_double;

	while(cin >> t_double) {
		doubles.push_back(t_double);
	}

	double total = 0;
	double count = doubles.size();
	for (vector<double>::size_type i = 0 ; i < count ; ++i) {
		total += doubles[i];
	}

	cout << "the average of the vector<double> is " << total / count << endl; 

}