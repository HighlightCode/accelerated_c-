#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

//using std::find;
//using std::find_if;

// define in cctype
using std::isalnum;
using std::isalpha;
using std::isdigit;

//using std::search;
using std::string;
using std::vector;

bool not_url_char(char);

string::const_iterator
url_end(string::const_iterator, string::const_iterator);

string::const_iterator
url_beg(string::const_iterator, string::const_iterator);

namespace ch6
{

template<class InputIt, class T>
constexpr InputIt find(InputIt first, InputIt last, const T& value)
{
	for(; first!=last; ++first) {
		if(*first == value) 
			return first;
	}
	return last;
}

template<class InputIt, class UnaryPredicate>
constexpr InputIt find_if(InputIt first, InputIt last, UnaryPredicate p) 
{
	for(; first != last; ++first) {
		if(p(*first)) {
			return first;
		}
	}
	return last;
}

template<class ForwardIt1, class ForwardIt2>
constexpr ForwardIt1 search(ForwardIt1 first, ForwardIt1 last,
							ForwardIt2 s_first, ForwardIt2 s_last)
{
	for(;;++first) {
		ForwardIt1 it = first;
		for (ForwardIt2 s_it = s_first;; ++it, ++s_it) {
			if (s_it == s_last) 
				return first;
			if (it == last)
				return last;
			if (!(*it == *s_it)) 
				break;
		}
	}
}

};

//url function in ch6 starts
vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	//look through the entire input
	while (b != e) {
		
		// look for one or more letters followed by `://'
		b = url_beg(b,e);

		if (b != e) {
			//get the rest of the url
			iter after = url_end(b,e);

			ret.push_back(string(b,after));

			b = after;
		}
	}
	return ret;
}


string::const_iterator
url_end(string::const_iterator begin, string::const_iterator end)
{
	return ch6::find_if(begin,end,not_url_char);
}

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	// see whether `c' can appear in a \s-1URL\s0 and return the negative
	return !(isalnum(c) || 
		ch6::find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";

	typedef string::const_iterator iter;

	iter i = b;

	while ((i = ch6::search(i, e, sep.begin(), sep.end())) != e) {
		if (i != b && i + sep.size() != e) {

			// 'beg' marks the beginnig of the protocol-name
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
				--beg;

			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}
		i += sep.size();
	}
	return e;
}




