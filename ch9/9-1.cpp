#include "./src/student_info_v2.h" // redefinition of student_info
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

int main() {

	vector<Student_info_V2> students;
	Student_info_V2 record;
	string::size_type maxlen = 0;

	// read data and store the data;
	while(record.read(cin)) {
		maxlen = max(maxlen , record.name().size());
		students.push_back(record);
	}

	// alphabetize the student record;
	sort(students.begin(), students.end(), compare_v2);

	// write the names and grades
	for (vector<Student_info_V2>::size_type i = 0;
    i != students.size(); ++i) {
	    cout << students[i].name()
	  		<< string(maxlen + 1 - students[i].name().size(), ' ');
	    try {
			streamsize prec = cout.precision();
			cout << setprecision(3) << students[i].grade() << setprecision(prec) << endl;
	    }
	    catch (domain_error e) {
	  		cout << e.what() << endl;
	    }
  	}
  	return 0;
}