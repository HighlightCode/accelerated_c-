#include <iostream>

int main()
{
	// std:: 의 코드는 해당 이름이 std 라는 네임스페이스에 속해 있음을 나타낸다. 
	std::cout << "Hello World!" << std::endl;
	/*
	주석은 다음과 같이 나타낸다.
	또한 << , >> 연산자들에 대해서 살펴보게 되면 << 연산자는 왼쪽우선결합성
	이라는 성질 때문에, 자신을 기준으로 왼쪽의 모든 부분과 오른쪽의 최소 부분을
	피연산자로 사용. --> (std::cout<<"Hello World!") << std::endl;
	*/
	/*
	<< STREAM 이란 ??
	- 따라서 내부의 std::cout을 반환하는 ostream 타입이고, 오른쪽의 std::endl;
	을 반환하는 조작어라면, << 연산자는 주어진 스트림에 관해 조작어의 동작을 실행 후
	해당 스트림 반환.
	*/
	return 0;
}