#include "Student_info.h"

using std::istream; using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name > y.name;
}

istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;

	if (is) {
		read_hw(is, s.homework);
	}
	return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		// if istream exists, get rid of previous values in hw
		hw.clear();

		// read homework grades
		double x;
		while ( in >> x)
			hw.push_back(x);

		// if EOS occurs, clear the istream
		in.clear();
	}
	return in;
}