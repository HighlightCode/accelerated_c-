#include <iostream>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <vector>

using std::cin; using std::cout;
using std::vector; using std::endl;
using std::end; using std::domain_error;
using std::sort; using std::ostream_iterator;
using std::copy; using std::begin;

template <class T, class Ran>
T median(Ran lhs, Ran rhs) {
	vector<T> v(lhs, rhs);

	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw domain_error("median of an empty container");

	sort(v.begin(), v.end());
    size_t mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid]; 
}


int main() {
	double a_double[] = { 10.0, 15.1, 55.3 };
	vector<double> v_double(a_double, end(a_double));
	cout << "before call median function : ";
	copy(begin(a_double), end(a_double), ostream_iterator<double>(cout,", ") );
	cout << endl;
	int a_int[] = { 10, 20, 30, 40, 50, 60, 70 };
	vector<int> v_int(a_int, end(a_int));
	cout << "before call median function, v_double are :  ";
	copy(begin(v_int), end(v_int), ostream_iterator<int>(cout,", ") );
	cout << endl;
	
	
	cout << median<double, double*>(a_double, end(a_double)) << endl;
	cout << median<double, vector<double>::iterator>(v_double.begin(), v_double.end()) << endl;
	cout << median<int, int*>(a_int, end(a_int)) << endl;
	cout << median<int, vector<int>::iterator>(v_int.begin(), v_int.end()) << endl;

	cout << "after call median function : ";
	copy(begin(a_double), end(a_double), ostream_iterator<double>(cout,", ") );
	cout << endl;
	cout << "before call median function, v_int are : ";
	copy(begin(v_int), end(v_int), ostream_iterator<int>(cout,", ") );
	cout << endl;
	return 0;
}