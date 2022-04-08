#include "./src/student_info.h"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <exception>

using std::vector; using std::string;
using std::sort; using std::max;
using std::cin; using std::cout;
using std::endl; using std::streamsize;
using std::setprecision; using std::domain_error;

string letter_grade(double grade)
{
	// range posts for numeric grades 
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
  	};

	// names for the letter grades
	static const char* letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	// compute the number of grades given the size of the array
	static const size_t n_grades = sizeof(numbers) / sizeof(*numbers);
	// given a numeric grade, find and return the associated letter grade
	for (size_t i=0; i < n_grades; i++) {
		if (grade >= numbers[i])
			return letters[i];
	}
	return "?\?\?";
}

int main() {

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read data and store the data;
	while(record.read(cin)) {
		maxlen = max(maxlen , record.name().size());
		students.push_back(record);
	}

	// alphabetize the student record;
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0;
    i != students.size(); ++i) {
	    cout << students[i].name()
	  		<< string(maxlen + 1 - students[i].name().size(), ' ');
	    try {
			double final_grade = students[i].grade();
			cout << letter_grade(final_grade) << endl;
	    }
	    catch (domain_error e) {
	  		cout << e.what() << endl;
	    }
	}
	return 0;

}
