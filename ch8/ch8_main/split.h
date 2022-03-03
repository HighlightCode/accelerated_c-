#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm>
#include <cctype>
#include <string>

using std::find_if;
using std::string;

using std::isspace;

inline bool space(char c)
{
	return isspace(c);
}

inline bool not_space(char c)
{
	return !isspace(c);
} 

template<typename Out>
void split(const string& str, Out os)
{
	typedef string::const_iterator iter;

	iter i = str.begin();
	while(i != str.end()) {
		//ignore leading blocks
		i = find_if(i,str.end(), not_space);

		//find end of next word
		iter j = find_if(i,str.end(),space);

		// copy the characters in [i,j]
		if (i != str.end())
			*os++ = string(i,j);
		
		i=j;
	}
}

#endif