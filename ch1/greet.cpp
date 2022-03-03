// 이름을 물어보고, 환영하는 프로그램 작성
#include <iostream>
#include <string>

int main()
{
	//cout<< 을 통해 출력 버퍼에 출력 내용이 저장
	std::cout << "Please enter your first name: ";

	// 이름 입력을 받게 되면서, 출력버퍼를 지우고, 화면에 메시지 출력
	std::string name;     
	std::cin >> name;     

	// greeting message 출력
	std::cout << "Hello, " << name  << "!" << std::endl;
	return 0;
}
