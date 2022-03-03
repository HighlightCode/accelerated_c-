### Q6: What does the following code do?
```
int i = 0;
while (i < 10) {
    i += 1;
    std::cout << i << std::endl;
}
```
outputs the numbers from 1 to 10. 
"1"
"2"
.
.
.
"10"

### Q10: Explain each of the uses of `std::` in the following program:
```
int main()
{
    int k = 0;
    while (k != 10) {               // invariant: we have written k asterisks so far
        using std::cout;
        cout << "*";
        ++k;
    }
    std::cout << std::endl;         // std:: is required here
    return 0;
}
```
`using` statement is valid for the block it has been used only.so outside that block, we must still use `std::cout`.