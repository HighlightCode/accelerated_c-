#include "./src/Str.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
  Str greeting = "Hello , how are you?";
  Str name = "Geert";

  greeting.insert(greeting.begin() + 6, name.begin(), name.end());

  cout << greeting << endl;

  return 0;
}