#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string; using std::sort;
using std::pair;

typedef vector<string>::size_type vec_sz;

std::istream& read_words(std::istream& in, vector<pair<string,int>>& words) {
	if (in) {
		string word;
		bool is_counted = false;
		word.clear();

		while (in >> word) {
			is_counted = false;
			for(auto &i: words){
				if (i.first == word) {
					++(i.second);
					is_counted = true;
					break;
				}
			}
			if(!is_counted) {
				words.push_back(std::make_pair(word,1));
			}
		}
		in.clear();
	}
}

bool compare(const pair<string,int>& w1, const pair<string,int>& w2) {
	if (w1.second == w2.second)
		return w1.first > w2.first;
	else
		return w1.second > w2.second;
}

int main() 
{
	vector<pair<string,int>> words;

	read_words(cin, words);
	sort(words.begin(), words.end(), compare);

	pair<string,int> word = words[0];
    vec_sz count = 0;
    for (vec_sz i = 0; i < words.size(); ++i)
        cout << "Word " << words[i].first << " appeared "
            << words[i].second << " time"  << endl;

    return 0;
	
}