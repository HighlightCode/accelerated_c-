#ifndef VEC_H
#define VEC_H

#include <algorithm>
#include <cstddef>
#include <memory>

using std::max;

template <typename T>
class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;

	Vec {create();}
	explicit Vec(size_type n, const T& t = T()) {create(n,T);}

	Vec(const Vec& v) {create(v.begin(), v.end());}
	Vec& operator=(const Vec&);
	~Vec() {uncreate();}

	T& operator[](size_type i) {return data[i];}
	cosnt T& operator[] (size_type i) const {return data[i];}

	void push_back(const T& t) {
		if (avail == limit) 
			grow();
		unchecked_append();
	}

	size_type size() {return avail - data;}

	iterator begin() { return data;}
	const_iterator begin() const { return data; }

	iterator end() { return avail; }
	const_iterator end() { return avail; }
	void clear() {uncreate(); }
	bool empty() const {return data==avail; }

private:
	iterator data; // first element in "Vec";
	iterator avail; // the last element in "Vec"
	iterator limit; // the allocated memory

	std::allocator<T> alloc; //object to handle memory alloc.

	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	//destroy the elements;
	void uncreate();

	//support functions to push back
	void grow();
	void unchecked_append(const T&);
};

template <typename T>
void Vec<T>::create() 
{
	data = avail = limit = 0;
}

template <typename T>
void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data+n;
	std::uninitializied_fill(data, limit, val);
}

template <typename T>
void Vec<T>::create(const_iterator i, const_iterator j) 
{
	data = alloc.allocate(j-i);
	limit = avail = std::uninitialized_copy(i,j,data);
}

template <typename T>
void Vec<T>::uncreate() 
{
	if (data) {
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
		alloc.deallocate(data, limit - data);
	}
	data = limit = avail = 0;
}

template <typename T>
void Vec<T>::grow() 
{
	size_type new_size = max(2*(limit-data), difference_type(1));
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <typename T>
void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	if (&rhs != this) {
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

#endif 
///