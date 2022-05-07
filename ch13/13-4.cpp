#include <algorithm>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "./src/Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::string;
using std::vector;

int main() {
	cout << "Enter a Core student: " << endl;
	Core core(cin);
	cout << "Grade: " << core.letter_grade() << endl;

	cout << "Enter a Grad student: " << endl;
	Grad grad(cin);
	cout << "Grade: " << grad.letter_grade() << endl;

	return 0;
}