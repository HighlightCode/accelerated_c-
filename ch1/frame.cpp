#include <iostream>
#include <string>

int main()
{
	std::cout<< "PLEASE ENTER YOUR NAME: ";
	std::string name;
	std::cin >> name;

	// 메시지 빌드 
	const std::string greeting = "HELLO, " + name + "! ";

	// 두번째 줄과 4번째줄을 작성
	const std::string spaces(greeting.size(),' ');
	const std::string second = "* " + spaces + " *";

	// 1번째 줄과 5번째 줄을 작성
	const std::string first(second.size(), '*');

	//출력 스트림 작성
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;
	
	return 0;
}