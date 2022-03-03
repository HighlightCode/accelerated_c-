#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

using namespace std;


int main() {
    string str;
    cout << "Hello World!\n";\
    getline(cin,str); // 표준입력방식으로 str에 문자열 끝까지 저장
    getline(cin,str,'\n'); 
}