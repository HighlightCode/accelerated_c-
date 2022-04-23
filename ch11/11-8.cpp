#include "./src/List.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main() {
	LList<int> list;
	list.push_back(5);
	list.push_back(10);
	list.push_back(15);

	LList<int>::iterator iter = list.begin();

	cout << *++iter << endl;
	cout << *--iter << endl;

	while (iter != list.end())
		cout << *iter++ << endl;

	LList<string> stringlist(5, "test");
	cout << " stringlist " << endl;
	LList<string>::iterator listIter = stringlist.begin();
	cout << *listIter << endl;
	
	while (listIter != stringlist.end())
		cout << *listIter++ << endl;

	LList<string> stringlist_copy = stringlist;
	cout << " stringlist_copy " << endl;
	if (stringlist_copy.size() > 0) {
		listIter = stringlist_copy.begin();
		while (listIter != stringlist.end())
			cout << *listIter++ << endl;
	}

	return 0;
}