#include "./src/Vec.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
  string s = "A lonesome string.";

  Vec<char> v(s.begin(), s.end());

  for (size_t i = 0; i < v.size(); i++)
    cout << v[i];

  cout << endl;

  return 0;
}