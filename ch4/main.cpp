#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"
#include "grade.h"

using std::cin; using std::setprecision;
using std::cout; using std::sort;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;

int main()
{
	vector<Student_info> students;
	Student_info record;

	string::size_type max_len = 0 ; 

	while (read(cin, record)) {
		max_len = max(max_len, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0 ; i != students.size() ; i++) {
		cout << students[i].name << string(max_len + 1 - students[i].name.size(), ' ');

		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision(); 
			cout << setprecision(3) << final_grade << setprecision(prec);
		} 
		catch ( domain_error(e)){ 
			cout << e.what();
		}
		cout << endl;
	}
	return 0;	
}
