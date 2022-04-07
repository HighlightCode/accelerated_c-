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
	    cout << i << " " << students[i].name()
	  		<< string(maxlen + 1 - students[i].name().size(), ' ');
	    if(students[i].valid()) {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
	   	else {
	  		cout << "Invalid Student Input .. !" << endl;
	    }
	}
  	return 0;
	
}