#ifndef GUARD_MEDIAN
#define GUARD_MEDIAN

#include <algorithm>
#include <vector>
#include <stdexcept>

template <typename T>
T median(vector<T> vec)
{
	typename typedef std::vector<T>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size==0)
		return domain_error("median of an empty error");

	sort(vec.begin(), vec.end());
	vec_sz mid = size/2;

	return (size%2 == 0) ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

#endif