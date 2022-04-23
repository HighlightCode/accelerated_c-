#include "./src/Str_c.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
  Str_c greeting = "Hello buddy!";
  Str_c::const_iterator iter = greeting.begin();

  while (iter != greeting.end())
    cout << *iter++;

  cout << endl;

  return 0;
}