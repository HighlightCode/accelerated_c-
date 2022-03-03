#include <iostream>
#include <string>

using std::cin; using std::endl;
using std::cout; using std::string;

int main()
{
	//ask for the person's name
	cout << "Please enter your first name : ";

	// read the name
	string name;
	cin >> name;

	//build the message that we intend to write 
	const string greeting = "Hello, " + name + "!";
	const int pad = 1;
	
	// the number of rows and columns to write
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	// write a blank
	cout << endl;

	// write 'rows' rows of output
	for (int r = 0; r != rows; ++r ) {
		string::size_type c = 0;
		while(c != cols) {

			//invariant : we have written 'c' characters so far in the current row
			if ( r == pad && c == pad+1 ) {
				cout << greeting;
				c += greeting.size();
			} else {
				if (r == 0 || r == rows - 1 || 
					c == 0 || c == cols -1)
					cout << "*";
				else 
					cout << " ";
				++c;
			}
			
		}
		cout << endl;
	}
	return 0;
}