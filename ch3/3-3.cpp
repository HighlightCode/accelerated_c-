#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>

using std::cout;using std::cin;
using std::endl;using std::vector;
using std::sort;using std::string;

int main()
{
	// ask for the string input
	cout << "Enter the sentences, followed end-of-file " << endl;

	vector<string> words;
	vector<int> counts;
	typedef vector<string>::size_type vec_sz;
	string word;
	vec_sz size;
	
	// read the sentences
	while (cin >> word) {
		int found_idx = -1;
		size = words.size();
		// search vec for the word
		for (vec_sz i = 0; i < size ; i++) {
			if(words[i] == word)
				found_idx = i;
		}
		if (found_idx >= 0)
			++counts[found_idx];
		else {
			words.push_back(word);
			counts.push_back(1);
		}
	}
	// write the results
    size = words.size();
    for (vec_sz i = 0; i < size; ++i)
        cout << "Word: " << words[i] << ", Count: " << counts[i] << endl;

    return 0;
}