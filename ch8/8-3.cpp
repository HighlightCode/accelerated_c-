#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <iterator>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::chrono::steady_clock;

// ch8.1.1 median function
template<class T>
T median(std::vector<T> v) {
	typedef typename std::vector<T>::size_type vec_sz;
  	vec_sz size = v.size();
  	if (size == 0)
    	throw std::domain_error("median of an empty vector");
  	std::sort(v.begin(), v.end());

  	vec_sz mid = size / 2;
  	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

template<class Ran, class T>
T median_iter(Ran b, Ran e)
{
	T size = std::distance(b, e);
	if (size == 0) 
		throw std::domain_error("median of an empty vector :: median_iter");
	std::sort(b,e);

	T mid = size / 2;
	std::advance(b, mid - 1);
	
	return size % 2 == 0 ? (*b++ + *b) / 2 : *++b;
}

int main() 
{
	vector<int> vec1 = { 85, 74, 75, 45, 49 , 66};

  	// sorting the vector so the sorting step in the median functions won't affect performance
  	std::sort(vec1.begin(), vec1.end());

	steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (int i = 0; i < 100; i++) {
		median(vec1);
	}

	steady_clock::time_point end = std::chrono::steady_clock::now();

	cout << "Microseconds to run median 100 times using pass by value = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

  	begin = std::chrono::steady_clock::now();
	for (int i = 0; i < 100; i++) {
    	median_iter<vector<int>::iterator, int>(vec1.begin(), vec1.end());
  	}

	end = std::chrono::steady_clock::now();
	cout << "Microseconds to run median 100 times using iterators = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;

	return 0;
}