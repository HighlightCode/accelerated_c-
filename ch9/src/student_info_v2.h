#ifndef GUARD_student_info_V2_H
#define GUARD_student_info_V2_H

#include <string>
#include <vector>
#include <iostream>

class Student_info_V2 {

private:
	std::string n;
	double midterm, final;
	double g;
	std::vector<double> homework;

public:
	Student_info_V2();
	Student_info_V2(std::istream&);
	
	std::istream& read(std::istream&);
	double grade() const;
	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }
};

bool compare_v2(const Student_info_V2&, const Student_info_V2&);

#endif 