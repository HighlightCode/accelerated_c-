#include "student_info.h"

#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

using std::istream; using std::vector;
using std::domain_error; using std::sort;


Student_info::Student_info() : midterm(0), final(0) {}

Student_info::Student_info(istream& is) { read(is); } 

istream& Student_info::read(istream& is) 
{
	is >> n >> midterm >> final;
	read_hw(is, homework);
	return is;
}

istream& read_hw(istream& is, vector<double>& hw)
{
	if(is) {
		hw.clear();
		is.clear();
		
		double x;
		while(is >> x)
			hw.push_back(x);
		is.clear();
	}

	return is;
}

double Student_info::grade() const 
{
	return ::grade(midterm, final, homework);
}

double grade(double midterm, double final, const vector<double>& hw) 
{
	if (hw.size() == 0)
		throw domain_error("Student must have done homework");
	return grade(midterm,final, median(hw));
}

double grade(double midterm, double final, double homework)
{
	return 0.2 *midterm + 0.4 * final + 0.4 * homework;
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}