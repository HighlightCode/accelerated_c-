#ifndef __STUDENT_INFO_H
#define __STUDENT_INFO

#include <string>
#include <vector>
#include <iostream>

struct Student_info 
{
	std::string name; 
	std::vector<double> homework;
	double midterm;
	double final;
}

double grade_aux(const Student_info&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info&);
std::istream& read(std::istream&, std::vector<Student_info>&);
std::vector<Student_info> extract(std::vector<Student_info>&, bool criteria(const Student_info&));
bool did_all_hw(const Student_info&);

#endif


