#ifndef __SPLIT_H_
#define __SPLIT_H_

#include <algorithm>
#include <string>
#include <vector>

inline bool space(char c)
{
        return std::isspace(c);
}

inline bool not_space(char c)
{
        return !std::isspace(c);
}

template <class Out>
void split(const std::string& Str, Out os)
{
	typedef std::string::const_iterator iter;
	iter i = Str.begin();

	while(i != Str.end()) {
		i = std::find_if(i, Str.end(), not_space);

		iter j = find_if(i,Str.end(), space);

		if (i != Str.end())
			*os++ = string(i,j);

		i=j;
	}
}

#endif