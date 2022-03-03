#include <iostream>
#include <iomanip>
#include "math.h"

using std::cin; using std::cout;
using std::endl;
using std::setw; using std::pow;
/*
	std::setw : Sets the field width to be used on output operations.
*/

int main() 
{
	int n = 100;
	for(int i = 1; i < 100; i++) {
		cout << setw(3) << i << setw(5) <<  pow(i,2) << endl;;
	}
	
}