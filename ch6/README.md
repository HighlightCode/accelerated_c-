## Questions and Solutions


### Q3: What does this program fragment do?
```
vector<int> u(10, 100);
vector<int> v;
copy(u.begin(), u.end(), v.begin());
```
```c++
template<class InputIterator, class OutputIterator>
  OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result)
{
  while (first!=last) {
    *result = *first;
    ++result; ++first;
  }
  return result;
}
```
does not work. due to v does not have enough memory to copy. you need to insert back_inserter or else thing.