#include "words.h"
#include "split.h"
#include "numbers.h"

#include <string>
#include <map>
#include <istream>
#include <vector>
#include <algorithm>
#include <exception>

using std::string;    using std::map;
using std::istream;   using std::ostream;
using std::endl;      using std::vector;
using std::find_if;   using std::getline;
using std::logic_error;

Grammar read_grammar(istream& in) 
{
	Grammar ret; 
	string line;

	while (getline(in,line)) {
		vector<string> entry = split(line);

		if (!entry.empty())
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}
}

vector<string> gen_sentence(const Grammar& g)
{
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
	if(!bracketed(word))
		ret.push_back(word);
	else {
		Grammar::const_iterator it = g.find(word);

		if(it == g.end())
			throw logic_error("empty rule");

		const Rule_Collection& c = it -> second;

		const Rule& r = c[nrand(c.size())];

		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
      		gen_aux(g, *i, ret);
	}
}