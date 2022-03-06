#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <chrono>

#include "Student_info.h"
#include "grade.h"

using std::cout; using std::sort;
using std::endl; using std::string;
using std::max; using std::vector;
using std::ifstream; using std::chrono::steady_clock;

vector<Student_info> extract_fails_remake(vector<Student_info>& v)
{
	typedef vector<Student_info>::size_type v_sz;
	vector<Student_info> v_out;
	v_sz counter = 0;

	for (v_sz i = 0 ; i < v.size(); i++) {
		if (fgrade(v[i])) {
			v_out.push_back(v[i]);
		} else {
			v[counter++] = v[i];
		}
	}

	v.resize(counter);
	
	return v_out;
}

int main() 
{
	string file = "../data/ch5/students10000.txt";
	ifstream infile;

	vector<Student_info> students, failed;
	infile.open(file);
	read(infile, students);
	infile.close();

	steady_clock::time_point begin = std::chrono::steady_clock::now();
	failed = extract_fails(students);
	steady_clock::time_point end = std::chrono::steady_clock::now();
  	cout << "Microseconds to extract failed from original_version : " <<
		std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
	
	begin = std::chrono::steady_clock::now();
	failed = extract_fails_remake(students);
	end = std::chrono::steady_clock::now();
  	cout << "Microseconds to extract failed from remake_version : " <<
		std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

  return 0;
	
}