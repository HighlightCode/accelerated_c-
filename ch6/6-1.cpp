#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout;
using std::max; using std::string;
using std::vector; using std::endl;

string::size_type width(const vector<string>& v)
{
	string::size_type max_len = 0;
	for(vector<string>::const_iterator iter = v.begin();
		iter != v.end();
		iter++) {
			max_len = max(max_len, iter->size());
	}
	return max_len;
}

vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4,'*');

	ret.push_back(border);

	for (vector<string>::const_iterator iter = v.begin();
		iter  != v.end();
		iter++) {
			ret.push_back("* " + (*iter) + string(maxlen-(iter->size()),' ') + " *");
		}
	ret.push_back(border);
	return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	string::size_type width1 = width(left) + 1;

	vector<string>::const_iterator lt = left.begin(), rt = right.begin();

	while(lt != left.end() || rt != right.end()) {
		string s;
		if (lt != left.end())
			s = *lt++;

		s += string(width1 - s.size(), ' ');

		if(rt != right.end())
			s += *rt++;
		ret.push_back(s);		
	}
	return ret;
}

int main()
{
    // create two vectors
    vector<string> v1 = {"this is an","example","to","illustrate","framing"};
	vector<string> v2 = {"what is","essential","is","invisible","to the eye"};

    // frame the vectors
    vector<string> framed_left = frame(v1);
    vector<string> framed_right = frame(v2);

    // horizontally concatenate
    vector<string> concatenated = hcat(framed_left, framed_right);

    // write the results
    for (vector<string>::const_iterator it = concatenated.begin();
        it != concatenated.end(); ++it) {
        cout << *it << endl;
	}

	cout << endl;
    return 0;
}