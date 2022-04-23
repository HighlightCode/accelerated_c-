#include "./src/List.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main() {
	LList<int> list;
	list.push_back(5);
	list.push_back(10);
	list.push_back(15);
	
	LList<int>::iterator iter = list.begin();
	LList<int>::iterator iter_e = list.end();
	
	cout << *++iter << endl;
	cout << *--iter << endl;

  	while (iter != iter_e){
		cout << *iter++ << endl;
	}
	
	LList<string> stringlist(5, "test");
	LList<string> stringlist_copy = stringlist;
	LList<string>::iterator listIter = stringlist.begin();

	//*listIter = "first";

	while (listIter != stringlist.end())
    	cout << *listIter++ << endl;

	if (stringlist_copy.size() > 0) {
		listIter = stringlist_copy.begin();
		while (listIter != stringlist.end())
	  		cout << *listIter++ << endl;
	}

  return 0;
}