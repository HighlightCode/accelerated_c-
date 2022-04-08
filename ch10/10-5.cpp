#include "./src/string_list.h"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::cin; using std::cout;
using std::copy; using std::endl;
using std::string;


int main()
{
	String_list str_list;
	
	str_list.push_back("test");
	str_list.push_back("more");
	str_list.push_back("testing");
	str_list.push_back("even more");
	str_list.push_back("yup");
	
	String_list::iterator iter = str_list.begin();
	
	while (iter != str_list.end())
		cout << *iter++ << endl;
	cout << endl;
	
	iter = str_list.end();
	while (iter != str_list.begin())
		cout << *iter-- << endl;
	
	return 0;
}