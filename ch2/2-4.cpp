#include <iostream>
#include <string>

using std::cin;	using std::endl;
using std::cout; using std::string;

int main()
{
	cout<< "############## 2-4 START ##############"<<endl;
	cout<< "Please enter your name: ";

	// 이름 입력
	string name;
	cin >> name;

	// build the message that we want to write 
	const string greeting = "Hello, "+ name + "!";

	// greeting message 를 감싸는 padding 설정
	const int pad = 1;

	// row 와 col 설정
	const int rows = pad*2 + 3;
	const string::size_type cols = greeting.size() + pad*2 + 2;

	// write a blank line to seperate the output from input
	cout << endl;

	for(int r=0; r!=rows; r++)
	{
		string::size_type c = 0;
		static int extra_blank = static_cast<int>(cols)-2;
		while (c != cols) {
		// 메시지 출력
			if (r == pad + 1 && c == pad + 1) 
			{
				cout << greeting;
				c += greeting.size();
			} else {
				// 끝부분에 도달했을시 다음 과 같이 출력.
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
				{
					cout << "*";
					++c;
				}
				else if(r == pad+1)
				{
					cout<< " ";
					++c;
				}
				else
				{
					cout << string(extra_blank,' ');
					c += extra_blank;
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}