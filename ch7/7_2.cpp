#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <map>

using namespace std;


int main() {
    string s;

    map<string, int> counters;

    while(getline(cin,s)){
        if(s==""){
            break;
        }
        ++counters[s];
    }

    for (map<string,int>::const_iterator it = counters.begin();
        it != counters.end();
        ++it){
            cout<< it->first <<" "<< it->second<<endl;
        }
    return 0;
}