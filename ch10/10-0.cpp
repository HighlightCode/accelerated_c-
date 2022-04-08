#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <string.h>
#include <iterator>

using std::cin; using std::cout;
using std::endl; using std::cerr;
using std::ifstream; using std::ofstream;
using std::string; using std::getline;
using std::copy; 

int pointers()
{
	int x = 5;

	// pointers to x
	int* p = &x;
	cout << "x = " << x << endl;

	// change the value of x through p
	*p = 6;
	cout << "x = " << x << endl;
	return 0;
}

string letter_grade(double grade)
{
	// range posts for numeric grades 
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
  	};

	// names for the letter grades
	static const char* letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	// compute the number of grades given the size of the array
	static const size_t n_grades = sizeof(numbers) / sizeof(*numbers);
	// given a numeric grade, find and return the associated letter grade
	for (size_t i=0; i < n_grades; i++) {
		if (grade >= numbers[i])
			return letters[i];
	}
	return "?\?\?";
}

char* duplicate_chars(const char* p)
{
	// allocate enough space; remember to add one for the null;
	size_t length = strlen(p) + 1;
	char* result = new char[length];
	// copy into our newly allocated space and return pointer to first element
	copy(p, p + length, result);
	return result;
}

int main()
{
	pointers();
	cout << letter_grade(7560.0) << endl;
	char* str = duplicate_chars("test");
	cout << str << endl;
	return 0;
}