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
	Grad grad(cin);

	if(grad.valid())
		cout << "Grade : " << grad.grade() << endl;

	return 0;
}