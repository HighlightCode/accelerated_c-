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
using std::boolalpha;
using std::vector;

int main() {
	cout << "Enter a Core student: " << endl;
	Core core(cin);
	cout << " Is Core meet needs ? : " << boolalpha << core.requirements_met() << endl;

	cout << "Enter a Grad student: " << endl;
	Grad grad(cin);
	cout << " Is Grad meet needs ?: " << boolalpha << grad.requirements_met() << endl;

	return 0;
}