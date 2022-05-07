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
	// Must change the compile options to ANNOTATE Constructor OUTPUT.
	Core *p1 = new Core; // Core
	Core *p2 = new Grad; // Core & Grad
	Core s1;			 // Core
	Grad s2;			 // Core & Grad

	p1->grade();
	p1->name();

	p2->grade();
	p2->name();

	s1.grade();
	s1.name();

	s2.grade();
	s2.name();
}