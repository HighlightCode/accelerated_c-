#include <iostream>

int main()
{	
	/*
		\": 큰 따옴표를 문자열의 경계가 아닌 문자열의 일부로 취급
		\' : 문자 리터럴과의 일관성을 위해 문자열 리터럴에서의 ' 와 같은 의미
	*/
	std::cout << "This is (\") is a qoute, and this (\\) is a backslash" << std::endl;

	return 0;
}