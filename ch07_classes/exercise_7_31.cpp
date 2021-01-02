/*
- 練習7.31: 定義一對類別X與Y，其中X有指向Y的指標，而Y有型別為X的一個物件。
 */

#include <iostream>
#include <string>
using namespace std;


int main()
{
    class Y;
    class X{
        public:
            Y* ptY;
    };
    class Y{
        public:
        X memberX;
    };
    X dataX;
    Y dataY;
    return 0;
}