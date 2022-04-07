#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "./src/Student_info.h"
#include "./src/vec.h"

using namespace std;

template <class T>
double analysis(const vector<Student_info> &students, T grading_method) 
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grading_method);
	return median(grades);
}

template <class T>
void write_analysis(ostream& out, const string& name, T grading_method, 
					const vector<Student_info>& did, const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did, grading_method) << ", median(didnt) = " << analysis(didnt, grading_method) << endl;
}

int main()
{
	vector<Student_info> did, didnt;
	Student_info student;

	ifstream infile;

	infile.open("../data/ch8/students10.txt");
	read(infile, did);

	didnt = extract(did, did_all_hw);

	if(did.empty())
	{
		cout << "No student did all the homework!" << endl;
    	return 1;
	}

	if (didnt.empty())
	{
		cout << "Every student did all the homework!" << endl;
		return 1;
	}
	write_analysis(cout, "median", grade_aux, did, didnt);
  	write_analysis(cout, "average", average_grade, did, didnt);
  	write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);

  	return 0;
}