#include <iostream>
#include <string>

int main() 
{
	std::cout << "Please enter your first name : " << std::endl;
	std::string name;
	std::cin >> name;

	//message for cout 
	const std::string greeting = "Hello, " + name + "!";

	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";

	//messages for 2,4 columns
	const std::string first(second.size(), '*');

	// print out all
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;

	return 0;
}