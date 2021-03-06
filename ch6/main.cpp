#include <vector>
#include <iostream>

using std::vector; using std::cin;
using std::cout; using std::endl;

#include "student_info.h"

int main() {
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

	cout << endl;
	return 0;
}