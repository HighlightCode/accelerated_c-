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
using std::stable_partition;

vector<Student_info> extract_fails_hw(vector<Student_info>& students)
{	
	/*
	ectract_fails( ... ) {
		remove_copy_if(s.begin(), s.end(), back_inserter(fail), func);
		s.erase(remove_if(s.begin(),s.end(), func), s.end());
	}
	*/
	vector<Student_info>::iterator iter = stable_partition(students.begin(),students.end(), did_all_hw);
	vector<Student_info> not_all_hw(iter, students.end());
	students.erase(iter, students.end());

	return not_all_hw;
}

int main() 
{
	vector<Student_info> did, didnt;
	Student_info student;

	while(read(cin, student)) {
		did.push_back(student);
	}

	didnt = extract_fails_hw(did);
	
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