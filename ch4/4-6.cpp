#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"
#include "grade.h"
#include "4-6.h"

using std::cin; using std::setprecision;
using std::cout; using std::sort;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;
using std::istream;

bool compare_students (const Student_info_extra& x, const Student_info_extra& y) {
	return x.name < y.name;
}

//rewrite read function for the Student_info_extra struct 
istream& read(istream& is, Student_info_extra& s)
{
	double midterm, final;
	vector<double> homework;

	is >> s.name >> midterm >> final;
	read_hw(is,homework);

	if (is) 
		s.grade = grade(midterm, final, homework);

	return is;
}

int main() 
{
	vector<Student_info_extra> students;
  	Student_info_extra record;
  	string::size_type maxlen = 0;

	try {
		while (read(cin, record)) {
			maxlen = max(maxlen, record.name.size());
			students.push_back(record);
		}
	}
  	catch (domain_error e) {
		cout << e.what() << endl;
	}

	sort(students.begin(), students.end(), compare_students);

	for (vector<Student_info>::size_type i = 0; i != students.size(); i++)	{
    	cout << students[i].name << 
			string(maxlen + 1 - students[i].name.size(), ' ');
    	streamsize prec = cout.precision();
    	cout << setprecision(3) << students[i].grade << setprecision(prec);

    	cout << endl;
	}

	return 0;
}