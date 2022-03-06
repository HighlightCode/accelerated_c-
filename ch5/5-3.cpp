#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <chrono>

#include "Student_info.h"
#include "grade.h"

using std::cin; using std::setprecision;
using std::cout; using std::sort;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;
using std::ifstream; using std::chrono::steady_clock;
using std::list;

typedef vector<Student_info> student_v;
typedef list<Student_info> student_l;

void vector_student_info(string file, student_v& s)
{
	ifstream infile;
	student_v failed;

	infile.open(file);
	read(infile,s);
  	infile.close();
  	infile.clear();

	steady_clock::time_point begin = std::chrono::steady_clock::now();
	failed = extract_fails(s);
	steady_clock::time_point end = std::chrono::steady_clock::now();
	cout << "Microseconds to extract failed from " << file << " student vector = " <<
		std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

}


void list_student_info(string file, student_l& s)
{
	ifstream infile;
	student_l failed;

	infile.open(file);
	read(infile,s);
  	infile.close();
  	infile.clear();

	steady_clock::time_point begin = std::chrono::steady_clock::now();
	failed = extract_fails(s);
	steady_clock::time_point end = std::chrono::steady_clock::now();
	cout << "Microseconds to extract failed from" << file << " student list = " <<
		std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

}

void test_vector_list(string num)
{
	string file = "../data/ch5/students" + num + ".txt";

	student_v students_v;
	student_l students_l;

	vector_student_info(file, students_v);
	list_student_info(file, students_l);
}

int main() 
{	
	char buf[4096];
	char *res = realpath(".",buf);
	cout << res << endl;
	test_vector_list("10");
	test_vector_list("100");
	test_vector_list("1000");
	test_vector_list("10000");

	return 0;
}