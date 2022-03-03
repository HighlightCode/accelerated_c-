#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>

using std::cout;using std::cin;
using std::endl;using std::vector;
using std::sort;using std::string;

int main() 
{
	vector<string> students;
	vector<double> grades;
	string student;

	typedef vector<string>::size_type vec_sz;

	// set homework amounts;
	const int hw_count = 3;
	// ask for user input
    cout << "Please enter student name, followed by midterm grade, "
        "final grade, and " << hw_count << " homework grades."
        " Send end-of-file to finish submitting." << endl;

	while (cin >> student) {
		students.push_back(student);
		double midterm, final;
		double hw_sum = 0.0;

		cin >> midterm >> final;
		for (int i = 0; i < hw_count; ++i) {
            double grade;
            cin >> grade;
            hw_sum += grade;
        };

		grades.push_back(0.2 * midterm + 0.4 * final + 0.4 * hw_sum / hw_count);
	}

	// write the results;
	for (vec_sz i = 0; i < students.size(); ++i) {
		cout << "Student " << students[i] << "'s Final Grade; "<<
			grades[i] << "." << endl;
	}
	return 0;
}