#ifndef GUARD_Student_info
#define GUARD_Student_info


// Student _ Info Header file
#include <iostream>
#include <string>
#include "Vec.h"

struct Student_info {
	std::string name;
	double midterm, final;
	Vec<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read(std::istream&, Vec<double>&);

#endif 