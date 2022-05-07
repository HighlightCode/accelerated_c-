#include <algorithm>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "./src/Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store the data
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), Student_info::compare);

	// write the names and grades
	for (auto &student : students) {
		cout << student.name()
			 << string(maxlen + 1 - student.name().size(), ' ');
		try {
			double final_grade = student.grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec)
				 << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	
	return 0;
}