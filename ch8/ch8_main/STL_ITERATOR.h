// This file contains sample implementations of assorted algorithms
// from the standard library.  It is not actually used by any of the
// other code in the book.


//find function
template <typename In, typename X>
In find(In begin, In end, const X& x)
{
	while (begin != end && *begin != x)
		++begin;
	return begin;
}


//Copy function
template <typename In, typename Out>
Out copy(In begin, In end, Out dest)
{
	while(begin != end)
		*dest++ = *begin++;
	
	return dest;
}

//replace function -> for [begin,end] replace the value x to y
template<typename For, typename X>
void replace(For begin, For end, const X& x, const X& y)
{
	while(begin != end)
	{
		if (*begin == x)
			*begin = y
	}
	++begin;
}

template <typename Bi> 
void reverse(Bi begin, Bi end)
{
	while (begin != end) {
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}

template<typename Ran, typename X>
bool binary_search(Ran begin, Ran end, const X& x)
{
	while (begin < end)
	{
		// find the midpoint of the range
		Ran mid = begin + (begin + end) / 2;

		// see which part of the range contains `x'
		if(x<*mid)
			end = mid;
		else if (*<mid)
			begin = mid;
		// if we got here, then *mid == x so we're done.
		else
			return true;
	}
	return false;
}