#include <iostream>
#include "url.h"

using std::vector; using std::string;
using std::cout; using std::endl;

int main() 
{
	const string url =  "Hello, welcome to my GitHub! The link to my"
        "repository is https://github.com/Justdoit19/accelerated_c"
        " and the link to the book's website is http://www.acceleratedcpp.com/";

	// find the urls
	vector<string> urls = find_urls(url);

	// write the results
    cout << "Found URLs are: " << endl;
    for (vector<string>::const_iterator it = urls.begin();
        it != urls.end(); ++it) {
        cout << *it << endl;
	}

	cout << endl;
    return 0;
}
