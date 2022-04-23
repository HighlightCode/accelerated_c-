#include "./src/vec.h"
#include <iostream>
#include <iterator>
#include <algorithm>

using std::ostream_iterator;
using std::cin;
using std::cout;
using std::endl;

template <class T> void Vec<T>::destroy() {
	if (data) {
		// destroy the elements that were constructed
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
	}
	avail = data;
}

template <class T> typename Vec<T>::iterator Vec<T>::destroy(iterator pos) {
	if (data && pos != avail) {
		alloc.destroy(pos);
		iterator it = pos + 1;

		while (it != avail) {
			alloc.construct(pos++, *it++);
			alloc.destroy(pos);
		}
		avail = pos;
	}
	return avail;
}

template <class T>
typename Vec<T>::iterator Vec<T>::destroy(iterator b, iterator e) {
	if (data && b != avail && b != e) {
		iterator it = b;
		while (it != e)
			alloc.destroy(it++);

		while (e != avail) {
			alloc.construct(b++, *e);
			alloc.destroy(e++);
		}
		avail = b;
	}
	return avail;
}

int main() {
	Vec<int> v(10, 1);
	std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
	
	v.clear();
	std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
	
	for (Vec<int>::size_type i = 0; i < 10; i++)
	v.push_back(i);
	std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
	
	v.erase(v.begin() + 2);
	std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
	
	v.erase(v.begin() + 4, v.begin() + 7);
	std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

  return 0;
}