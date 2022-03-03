#include <iostream>

using namespace std;

int main() {
	cout<< "############## 2-9 START ##############"<<endl;	
	int a, b;
	cout << "Enter two numbers: ";
	cin >> a >> b;

	if (a > b)
		cout << "First is greater" << endl;
	else if (b > a)
		cout << "Second is greater" << endl;
	else
		cout << "Equal!" << endl;

	return 0;
	cout << endl;
}