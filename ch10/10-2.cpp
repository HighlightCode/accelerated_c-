#include <iostream>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <vector>

using std::cin; using std::cout;
using std::vector; using std::endl;
using std::end; using std::domain_error;
using std::sort;

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
	int a_int[] = { 10, 20, 30, 40, 50, 60, 70 };
	vector<int> v_int(a_int, end(a_int));
	
	cout << median<double, double*>(a_double, end(a_double)) << endl;
	cout << median<double, vector<double>::iterator>(v_double.begin(), v_double.end()) << endl;
	cout << median<int, int*>(a_int, end(a_int)) << endl;
	cout << median<int, vector<int>::iterator>(v_int.begin(), v_int.end()) << endl;
	
	return 0;
}