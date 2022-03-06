#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>

#include "student_info.h"
#include "vec.h"

using std::vector; using std::string;
using std::transform; using std::back_inserter;
using std::cin; using std::cout;
using std::endl; using std::ostream;

double optimistic_median_analysis(const vector<Student_info>& s)
{
	vector<double> grades;
	transform(s.begin(), s.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

double analysis(const vector<Student_info>& s, double method(const Student_info&))
{
	vector<double> grades;
	grades.reserve(s.end()-s.begin());
	transform(s.begin(), s.end(), back_inserter(grades), method);
	return median(grades);
}

void write_analysis(ostream& out, const string& name, double method(const Student_info&),
	const vector<Student_info>& did, const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did, method) << ", median(didnt) = " << analysis(didnt, method) << endl;
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

	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "optimistic meidan", optimistic_median_analysis, did, didnt);

	cout << endl;
	return 0;
}



