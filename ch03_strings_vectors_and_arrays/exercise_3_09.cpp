//g++ exercise_3_09.cpp && ./a.out
/*
 * 練習3.9: 下列程式會做什麼事？它是有效的嗎？如果不是，為何呢？
 * (某些)編譯會過，但是s是空字串，這樣做沒意義?
```
string s;
cout << s[0] << endl;
```
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string s;
    cout << s[0] << endl;
    return 0;
}