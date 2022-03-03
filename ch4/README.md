## Questions and Solutions

### Q1: We noted in §4.2.3/65 that it is essential that the argument types in a call to `max` match exactly. Will the following code work? If there is a problem, how would you fix it?
```
int maxlen;
Student_info s;
max(s.name.size(), maxlen);
```
since the type of `s.name.size()` is `size_t` and the type of `maxlen` is `int` so  the code will not work. if we change the type of 'maxlen' to 'size_t' then it will work. (static_cast<int> s.name.size())

### Q8: If the following code is legal, what can we infer about the return type of `f`?
```
double d = f()[n];
```
Since we can access the `n`th element of the return value, and know that it is a `double`, we can infer that `f`'s return type is a `double` container.