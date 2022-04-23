#ifndef GUARD_VEC_H
#define GUARD_VEC_H

#include <memory>
#include <algorithm>
#include <iterator>

template<class T>
class Vec{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	Vec() {
		create();
	}
	explicit Vec(size_type s, const T& t = T()) {
		create(s,t);
	}
	Vec(const Vec& v){
		create(v.begin(), v.end());
	}

	// for problem 12-14
	template<class In>
	Vec(In b, In e) {create(b,e);}

	Vec<T>& operator=(const Vec&);
	~Vec() {
		uncreate();
	}

	T& operator[](size_type i){
		return data[i];
	}
	const T& operator[](size_type i) const {
		return data[i];
	}

	void push_back(const T& t, bool double_grow = true) {
		if (avail==limit)
			grow(double_grow);
		unchecked_append(t);
	}

	size_type size() const {
		return avail - data;
	}

	iterator begin() {
		return data;
	}
	const_iterator begin() const {
		return data;
	}

	iterator end() {
		return avail;
	}
	const_iterator end() const {
		return avail;
	}

	void clear() {
		destroy();
	}

	iterator erase(iterator it) {
		return destroy(it);
	}
	iterator erase(iterator begin, iterator end) {
		return destroy(begin, end);
	}

	// for problem 12-12
	template<class In>
	void insert(iterator position, In first, In last) { insert_elements(position, first, last);};

	// for problem 12-13
	template<class In>
	void assign(In first, In last) { assign_elements(first, last); };

private:
	iterator data;
	iterator avail;
	iterator limit;

	std::allocator<T> alloc;

	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);
	template<class In>
	void create(In, In);

	void uncreate();

	void destroy();
	iterator destroy(iterator);
	iterator destroy(iterator, iterator);

	// support function for push_back;
	void grow(bool);
	void unchecked_append(const T&);

	template <class In>
  	void insert_elements(iterator, In, In);

  	template <class In>
  	void assign_elements(In, In);
};

template<class T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs) {
	// check for self assignment
	if (this != &rhs) {
		// free the array in the left side
		uncreate();
		// copy elements from the right-hand to left-hand side
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template<class T>
void Vec<T>::create() {
	data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T& val){
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template<class T>
void Vec<T>::create(const_iterator begin, const_iterator end)
{
	data = alloc.allocate(end - begin);
	limit = avail = std::uninitialized_copy(begin, end, data);
}

//for problem 12-14
template<class T>
template<class In>
void Vec<T>::create(In b, In e)
{
	data = alloc.allocate(e - b);
	limit = avail = (std::uninitialized_copy(b, e, data));
}

template<class T>
void Vec<T>::uncreate() {
	if(data) {
		// destroy the elements that were constructed;
		iterator it = avail;
		while (it != data) {
			alloc.destroy(--it);
		}
		alloc.deallocate(data, limit - data);
	}
}

template<class T>
void Vec<T>::grow(bool double_grow){
	size_type new_size;

	if(double_grow) {
		new_size = std::max(2 * (limit - data), ptrdiff_t(1));
	} else {
		new_size = limit - data + 1;
	}

	// allocate new space and copy
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	// return the old space;
	uncreate();

	// reset the pointers to point the newly allocated space;
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <class T> void Vec<T>::unchecked_append(const T &val) {
	alloc.construct(avail++, val);
}

template <class T>
void Vec<T>::destroy()
{
	if(data)
	{
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
	}	
	avail = data;
}

template<class T>
typename Vec<T>::iterator Vec<T>::destroy(iterator pos)
{
	if (data && pos != avail)
	{
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

template<class T>
typename Vec<T>::iterator Vec<T>::destroy(iterator b, iterator e)
{
  if (data && b != avail && b != e)
  {
    iterator it = b;
    while (it != e)
      alloc.destroy(it++);

    while (e != avail)
    {
      alloc.construct(b++, *e);
      alloc.destroy(e++);
    }

    avail = b;
  }
  return avail;
}

// for problem 12-12
template<class T>
template<class In>
void Vec<T>::insert_elements(iterator pos, In first, In last)
{
	Vec<T> tail(pos, avail);

	destroy(pos, avail);

	In iter1 = first;

	while (iter1 != last)
		push_back(*iter1++);

	iterator iter2 = tail.begin();
	while (iter2 != tail.end()) 
		push_back(*iter2++);
}

// for problem 12-13
template <class T>
template <class In>
void Vec<T>::assign_elements(In first, In last)
{
  	uncreate();
  	create(first, last);
}

#endif