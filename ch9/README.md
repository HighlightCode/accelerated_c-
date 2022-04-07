## Questions and Solutions

### Q2: If we define the `name` function as a plain, non`const` member function, what other functions in our system must change and why?
If we define the `name` function as a non`const` function, we need to change the `compare` function as it uses `const Student_info&` references.
'''
// we define the 'name' function as a 'const' function , like below
bool compare(const Student_info& x, const Student_info& y) {
	return x.name() < y.name();
}
'''
but if we define the 'name' function as a plain, we must call the 'name' as a 'nonconst' function like below.
'''
bool compare(Student_info& x, Student_info& y) {
	return x.name() < y.name();
}
'''

### Q7: The `read_hw` function §4.1.3/57 solves a general problem (reading a sequence of values into a `vector`) even though its name suggests that it should be part of the implementation of `Student_info`. Of course, we could change its name—but suppose, instead, that you wanted to integrate it with the rest of the `Student_info` code, in order to clarify that it was not intended for public access despite its apparent generality? How would you do so?
We could add the `read_hw` function as a `private` member function of the class `Student_info`, or we could put the definition of the `read_hw` function in the `Student_info.cpp` file without interfacing it to everyone.