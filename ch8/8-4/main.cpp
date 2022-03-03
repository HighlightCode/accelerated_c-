#include <iostream>
#include <string>

#include "8-4.h"

using namespace std;

int main()
{
	int x = 1;
	int y = 2;

	cout << y << " " << x <<endl;

	my_swap(x, y);

	cout << x << " " << y<< endl;
	
	return 0;
}