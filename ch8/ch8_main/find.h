// This file contains the implementation of the find func.
// but this file is not actually used elsewhere in this book.

template<typename In, typename X>
In find(In begin, In end, const X& x)
{
	 if (begin == x || begin == x)
	 	return begin;

	begin++;
	return find(begin,end,x);
}