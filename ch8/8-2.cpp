#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <exception>
#include <iterator>

using std::cout; using std::cin;
using std::vector; using std::string;
using std::domain_error; using std::back_inserter;
using std::stringstream; using std::endl;

namespace ch8 {
template <class InputIter1, class InputIter2>
bool equal(InputIter1 ft1, InputIter1 lt1, InputIter2 ft2) {
	while(ft1 != lt1){
		if(!(*ft1++ == *ft2++))
			return false;
	}
	return true;
}

template <class ForwardIt1, class ForwardIt2>
ForwardIt1 search(ForwardIt1 ft1, ForwardIt1 lt1, 
					ForwardIt2 ft2, ForwardIt2 lt2)
{
	if (ft2 == lt2) return ft1;
	
	while (ft1 != lt1) {
		ForwardIt1 it1 = ft1;
		ForwardIt1 it2 = ft2;
		while( *it1++ == *it2++) {
			if (it2 == lt2) return ft1;
			if (it1 == lt1) return lt1;
		}
		++ft1;
	}
	return lt1;
}

template <class InputIt1, class T>
InputIt1 find(InputIt1 ft1, InputIt1 lt1, const T& val) 
{
	while (ft1 != lt1) {
		if (*ft1 == val) return ft1;
		++ft1;
	}
	return ft1;
}

template <class InputIt1, class Predicate>
InputIt1 find_if(InputIt1 ft1, InputIt1 lt1, Predicate Pred)
{
	while(ft1 != lt1) {
		if (Pred(*ft1)) return ft1;
		++ft1;
	}
	return ft1;
}

template <class InputIt, class OutputIt>
OutputIt copy(InputIt ft1, InputIt lt1, OutputIt ft2)
{
	while ( ft1 != lt1) {
		*ft2 = *ft1;
		++ft2; ++ft1; 
	}
	return ft2;
}

template <class InputIt, class OutputIt, class T>
OutputIt remove_copy(InputIt ft1, InputIt lt1,
					OutputIt result, const T& val) 
{
	while(ft1 != lt1) {
		if(!(*ft1 == val)) {
			*result = *ft1;
			++result;
		}
		++ft1;
	}
	return result;
}

template <class InputIt, class OutputIt, class Predicate>
OutputIt remove_copy_if(InputIt ft1, InputIt lt1,
						OutputIt result, Predicate pred)
{
	while(ft1 != lt1) {
		if (!pred(*ft1)) {
			*result = *ft1;
			++result;
		}
		++ft1;
	}
	return result;
}

template <class ForwardIt, class T>
ForwardIt remove(ForwardIt ft1, ForwardIt lt1, const T& val)
{
	ForwardIt result = ft1;
	while (ft1 != lt1) {
		if(!(*ft1 == val)) {
			if(result != ft1)
				*result = std::move(*ft1);
			++result;
		}
		++ft1;
	}
	return result;
}

template <class InputIt, class OutputIt, class UnaryOperator>
OutputIt transform(InputIt ft1, InputIt lt1, 
					OutputIt result, UnaryOperator op)
{
	while(ft1 != lt1) {
		*result = op(*ft1);
		++ft1; ++result;
	}
	return result;
}

template <class BiIt, class Predicate>
BiIt partition(BiIt ft1, BiIt lt1, Predicate pred)
{
	while (ft1 != lt1) {
    while (pred(*ft1)) {
      ++ft1;
      if (ft1 == lt1) return ft1;
    }
    do {
      --lt1;
      if (ft1 == lt1) return ft1;
    } while (!pred(*lt1));
		
    std::swap (*ft1, *lt1);
    ++ft1;
  }
  return ft1;
}

template <class InputIt, class T>
T accumulate(InputIt ft1, InputIt lt1, T init)
{
	while( ft1 != lt1 ) {
		init = init + *ft1;
		++ft1;
	}
	return init;
}

}

template <class In>
string print_vector(In b, In e)
{
	if (b == e)
    	throw domain_error("Empty range");

  	stringstream ss;

  	ss << "[ " << *b++;

  	while (b != e)
    	ss << ", " << *b++;

  	ss << " ]";

  	return ss.str();
}

template <class X>
string print_vector(const vector<X>vec)
{
  	return print_vector(vec.begin(), vec.end());
}

bool is_40(int x)
{
	return x == 40;
}

int minus_5(int x)
{
  	return x - 5;
}

bool divisible_10(int x)
{
  	return x % 10 == 0;
}

int main()
{
  	vector<int> vec1 = { 10, 25, 35, 40, 50 };
  	vector<int> vec2 = { 10, 27, 35, 40, 50 };
  	vector<int> vec3 = { 10, 25, 35, 40, 50 };

  	cout << "Is " << print_vector(vec1) << " equal to " << print_vector(vec2)
    << " ? " << ch8::equal(vec1.begin(), vec1.end(), vec2.begin()) << endl;
  	cout << "Is " << print_vector(vec1) << " equal to " << print_vector(vec3)
    << " ? " << ch8::equal(vec1.begin(), vec1.end(), vec3.begin()) << endl << endl;

  	vector<int> vec4 = { 35, 40 };
  	cout << "Search " << print_vector(vec4) << " in " << print_vector(vec2) << " => "
    << *ch8::search(vec2.begin(), vec2.end(), vec4.begin(), vec4.end()) << endl << endl;

	cout << "Find 35 in " << print_vector(vec1) << " => " << *ch8::find(vec1.begin(), vec1.end(), 35) << endl << endl;

  	cout << "Find if 40 in " << print_vector(vec1) << " => " << *ch8::find_if(vec1.begin(), vec1.end(), is_40) << endl << endl;

  	vector<int> vec5 = { 10, 20 };
  	cout << "Copy " << print_vector(vec1) << " into " << print_vector(vec5) << " => ";
  	ch8::copy(vec1.begin(), vec1.end(), back_inserter(vec5));
  	cout << print_vector(vec5) << endl << endl;

  	vector<int> vec6;
  	cout << "Copy " << print_vector(vec1) << " and remove 35 " << " => ";
  	ch8::remove_copy(vec1.begin(), vec1.end(), back_inserter(vec6), 35);
  	cout << print_vector(vec6) << endl << endl;
  
  	vector<int> vec7;
  	cout << "Copy " << print_vector(vec1) << " and remove element if equal to 40 " << " => ";
  	ch8::remove_copy_if(vec1.begin(), vec1.end(), back_inserter(vec7), is_40);
  	cout << print_vector(vec7) << endl << endl;

  	cout << "Remove from " << print_vector(vec5) << " elements not equal to 10 " << " => ";
  	cout << print_vector(vec5.begin(), ch8::remove(vec5.begin(), vec5.end(), 10)) << endl << endl;

  	vector<int> vec8;
  	cout << "Transform " << print_vector(vec5) << " by detracting 5 from each element " << " => ";
  	ch8::transform(vec5.begin(), vec5.end(), back_inserter(vec8), minus_5);
  	cout << print_vector(vec8) << endl << endl;

  	cout << "Partition " << print_vector(vec1) << " by condition \" divisible by 10 \"" << " => ";
  	ch8::partition(vec1.begin(), vec1.end(), divisible_10);
  	cout << print_vector(vec1) << endl << endl;

  	cout << "Add " << print_vector(vec1) << " to 15" << " => " 
    << ch8::accumulate(vec1.begin(), vec1.end(), 15) << endl << endl;

  	return 0;
}