#include <iostream>
#include <iomanip>
#include "math.h"

using std::cin; using std::cout;
using std::setw; using std::endl;

int get_length(int n) {
	int length = 1;
	while (n / 10 > 0) {
		n /= 10;
		++length;
	}
	return length;
}


int main() 
{
	int n;
	cin >> n; 

	int forward_length_n = get_length(n);
	int backward_length_n = get_length(n * n);

	for (int i = 1 ; i <= n ; ++i) {
		cout << setw(forward_length_n) << i <<
			setw(backward_length_n + 1) << i*i << endl;
	}
	
}
