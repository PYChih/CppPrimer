/*
 * 練習2.15: 下列哪個定義是無效的(如果有的話)? 為什麼
(a). int ival = 1.01;
(b). int &rvall = 1.01;
(c). int &rval2 = ival;
(d). int &rval3;
/*
 * g++ exercise_2_15.cpp && ./a.out
 * 
 */
#include <iostream>
#include <string>
int main()
{
    int ival = 1.01;
    //int &rvall = 1.01;
    int &rval2 = ival;
    //int &rval3;
	return 0;
}