#include <iostream>
#include <string>

using std::cin; using std::endl;
using std::cout; using std::string;

int main()
{
	cout<< "############## 2-3 START ##############"<<endl;
	cout<< "Please enter your name: ";

	// enter the name
	string name;
	cin >> name;

	// message build 
	const string greeting = "Hello, " + name + "!";

	cout << "enter the pad: ";
	int pad;
	cin >> pad;
	
	// rows and cols
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;
	cout << endl;


	// write for the output
	for (int r = 0; r !=rows; r++)
	{
		string::size_type c = 0;

		while(c!=cols)
		{
			if (r == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();
			}
			else
			{
				if (r == 0 || r == rows-1 || 
					c == 0 || c == cols - 1)
					cout << "*";
				else 
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}