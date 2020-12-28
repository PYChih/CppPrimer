/*
- 練習5.18:
解釋下列的迴圈。更正你所偵測到的任何問題。
```
//a.
do // {}block
    int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2)
        cout <<"Sum is: " << v1 + v2 << endl;
while (cin);
//b
do {
    //...
}while (int ival = get_response());
//c
do {
    int ival =get_response();
} while (ival);
g++ exercise_5_18.cpp && ./a.out
```
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
//a.
    do{ // {}block
        int v1, v2;
        cout << "Please enter two numbers to sum:";
        if (cin >> v1 >> v2)
        cout <<"Sum is: " << v1 + v2 << endl;
    } while (cin);
//b
    //int ival;
    //do {
    //    //...
    //}while (int ival = get_response()); // can't define in do while(here)
//c
    //int ival;
    //do {
    //    int ival =get_response();
    //} while (ival);
	return 0;
}