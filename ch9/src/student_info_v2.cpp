#include "student_info_v2.h"
#include "student_info.h"

#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

using std::istream; using std::vector;
using std::domain_error; using std::sort;


Student_info_V2::Student_info_V2() : midterm(0), final(0), g(0) {}

Student_info_V2::Student_info_V2(istream& is) { read(is); } 

istream& Student_info_V2::read(istream& is) 
{
	is >> n >> midterm >> final;
	read_hw(is, homework);
	g = ::grade(midterm, final, homework);
	return is;
}

double Student_info_V2::grade() const 
{
	return g;
}

bool compare_v2(const Student_info_V2& x, const Student_info_V2& y)
{
	return x.name() < y.name();
}
