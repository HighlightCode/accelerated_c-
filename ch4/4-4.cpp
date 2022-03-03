#include <iostream>
#include <iomanip>
#include "math.h"

using std::cin; using std::cout;
using std::setw; using std::endl;
using std::streamsize; using std::setprecision;
using std::fixed;

int get_length(double n, const streamsize& decimal_points) {
	int length = 1;
	while (n / 10 > 1.0) {
		n /= 10;
		++length;
	}
	return length + decimal_points + 1;
}

int main()
{
	double num;
	cin >> num;

	streamsize decimal_points = 2;

	int forward_length = get_length(num, decimal_points);
	int backward_length = get_length(num * num, decimal_points);

	for (double i = 1.0 ; i < num ; ++i) {
		static streamsize prec = cout.precision();
		cout << fixed << setprecision(decimal_points) << setw(forward_length) << i 
			<< setw(backward_length + 1) << i * i << setprecision(prec) << endl;
	}

	return 0;
}