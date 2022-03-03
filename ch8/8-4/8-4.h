#ifndef GUARD_8_4
#define GUARD_8_4

template<typename T>
void my_swap(T& a,T& b)
{
	T c = a;
	a = b;
	b = c;
}

#endif