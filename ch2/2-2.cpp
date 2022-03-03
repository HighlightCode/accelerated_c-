#include <iostream>
#include <string>

using std::cin; using std::endl;
using std::cout; using std::string;

int main()
{
	cout<< "############## 2-2 START ##############"<<endl;
	cout<< "Please enter your name: ";

	// 이름 입력
	string name;
	cin >> name;

	// message build 
	const string greeting = "Hello, " + name + "!";

	//greeting 주변의 blank 작성
	const int h_pad = 1;
	const int v_pad = 2;

	// rows 와 cols 설정
	const int rows = v_pad*2 + 3;
	const string::size_type cols = greeting.size() + h_pad*2 + 2;
	cout << endl;


	// 출력 값 작성
	for (int r = 0; r !=rows; r++)
	{
		string::size_type c = 0;

		while(c!=cols)
		{
			if (r == v_pad+1 && c == h_pad +1)
			{
				cout << greeting;
				c += greeting.size();
			}
			else
			{
				if (r == 0 || r == rows-1 || c == 0 || c == cols - 1)
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