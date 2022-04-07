#ifndef GUARD_student_info_V6_H
#define GUARD_student_info_V6_H

#include <string>
#include <vector>
#include <iostream>

class Student_info_V6 {

private:
	std::string n;
	double midterm, final;
	double g;
	char f;
	std::vector<double> homework;

public:
	Student_info_V6();
	Student_info_V6(std::istream&);
	
	std::istream& read(std::istream&);
	double grade() const;
	char fail() const;
	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }
};

bool compare_v6(const Student_info_V6&, const Student_info_V6&);

#endif 