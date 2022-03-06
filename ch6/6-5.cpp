#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using std::vector; using std::cin;
using std::cout; using std::endl;
using std::transform; using std::back_inserter;

#include "student_info.h"
#include "vec.h"

double optimistic_median_analysis(const vector<Student_info>& s)
{
	vector<double> grades;
	transform(s.begin(), s.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

int main() 
{
	vector<Student_info> did, didnt;
	Student_info student;

	while(read(cin, student)) {
		if (did_all_hw(student)) 
			did.push_back(student);
		else
			didnt.push_back(student);
	}

	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
    	return 1;
	}

	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	write_analysis(cout, "optimistic meidan", optimistic_median_analysis, did, didnt);

	cout << endl;
	return 0;
}
