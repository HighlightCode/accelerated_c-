#include <iostream>
#include <list>
#include <sstream>
#include "Student_info.h"
#include "grade.h"


using std::istream; using std::vector;
using std::cout; using std::cin;
using std::list; using std::stringstream;


bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	double midterm, final;
	vector<double> homework;

	is >> s.name >> midterm >> final;

	if (is) {
		read_hw(is, homework);
		s.grade = grade(midterm, final, homework);
	}
	
	return is;
}

istream& read(istream& is, vector<Student_info>& v)
{
	const int BUFF_SIZE = 100;
	stringstream ss;
	char buff[BUFF_SIZE];

	while (is.getline(buff, BUFF_SIZE)) {
		ss << buff;
		Student_info student;
		read(ss, student);
		v.push_back(student);
	}

	return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		// if istream exists, get rid of previous values in hw
		hw.clear();

		// read homework grades
		double x;
		while ( in >> x)
			hw.push_back(x);

		// if EOS occurs, clear the istream
		in.clear();
	}
	return in;
}

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
		}
	}
	return fail;
}

list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
		}
	}
	return fail;
}