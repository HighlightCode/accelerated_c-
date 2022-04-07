#include "student_info_v6.h"
#include "student_info.h"

#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

using std::istream; using std::vector;
using std::domain_error; using std::sort;


Student_info_V6::Student_info_V6() : midterm(0), final(0), g(0) {}

Student_info_V6::Student_info_V6(istream& is) { read(is); } 

istream& Student_info_V6::read(istream& is) 
{
	is >> n >> midterm >> final;
	read_hw(is, homework);
	g = ::grade(midterm, final, homework);
	f = g >= 60 ? 'P': 'F';
	return is;
}

double Student_info_V6::grade() const 
{
	return g;
}

char Student_info_V6::fail() const 
{
	return f;
}

bool compare_v6(const Student_info_V6& x, const Student_info_V6& y)
{
	return x.name() < y.name();
}
