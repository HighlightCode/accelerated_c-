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
using std::istream;

int main()
{
  cout << "Enter a Credit student: " << endl;
  Credit credit(cin);
  cout << "Grade: " << credit.grade() << endl;
  cout << "is Credit Passed? " << credit.is_passed() << endl;

  return 0;
}