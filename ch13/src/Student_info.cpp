#include "Student_info.h"

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::min;
using std::string;
using std::vector;

istream& Student_info::read(istream &is) {
	delete cp; // delete previous object, if any
	char ch;
	is >> ch; // get record type
	if (ch == 'U')
		cp = new Core(is);
	else if (ch == 'C')
	 	cp = new Credit(is);
	else if (ch == 'A')
	 	cp = new Audit(is);
	else 
		cp = new Grad(is);
	return is;
}

Student_info::Student_info(const Student_info &s) : cp(0) {
	if (s.cp)
		cp = s.cp->clone();
}

Student_info &Student_info::operator=(const Student_info &s) {
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else {
			cp = nullptr;
		}
	}
	return *this;
}

string Core::name() const {
	return n;
}

double Core::grade() const{
	return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in) {
	in >> n >> midterm >> final;
	return in;
}

istream& Core::read(istream& in) {
	read_common(in);
	read_hw(in, homework);
	return in;
}

istream& Grad::read(istream& in) {
	read_common(in);
	in >> Grad::thesis;
	read_hw(in, homework);
	return in;
}

double Grad::grade() const {
	return min(Core::grade(), thesis);
}

string Core::letter_grade() const {
	static const double numbers[] = {
    97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
  };

  static const char* const letters[] = {
    "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
  };

  static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

  double result = grade();

  for (size_t i = 0; i < ngrades; ++i) {
    if (result >= numbers[i])
      return letters[i];
  }
  return "?\?\?";
}

bool compare(const Core& c1, const Core& c2) {
	return c1.name() < c2.name();
}

bool compare_Core_pts(const Core* cp1, const Core* cp2) {
	return compare(*cp1, *cp2);
}

istream& read_hw(istream& is, vector<double>& hw) {
	if(is) {
		is.clear();
		double x;
		while(is >> x) {
			hw.push_back(x);
		}
		is.clear();
	}
	return is;
}

double grade(double midterm, double final, const vector<double>& hw) {
	if(hw.size() == 0)
		throw domain_error("Student has done no homework.!");
	return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework) {
	return 0.2 *midterm + 0.4 * final + 0.4 * homework;
}

double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of empty vector");
	
	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}