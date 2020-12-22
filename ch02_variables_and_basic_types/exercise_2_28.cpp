/*
 * - 練習2.28: 解釋下列定義。指出其中非法的定義。
a int i, *const cp;//cp是一個const指標，就是說它指了之後就不能變了，所以一開始要給好
b int *p1, *const p2; //p1是指向int的指標，p2是指向int的const指標，所以p2要init
c const int ic, &r = ic;//ic是一個const int一開始要先給值，r是對一個const int的參考，所以const int &r = ic是可以的，ic要先定義喔，然後管它是不是const都可以
d const int *const p3;//p3是一個const指標，所以一開始要先指著某個人喔
e const int *p//指向const int的指標，不用一開始就先指好
 */
/*
 * g++ exercise_2_28.cpp && ./a.out
 */
#include <iostream>
int main()
{
    //int i;//, *const cp; // init
    //int *p1, *const p2;
    int ic;
    const int i=0, &r = ic;
    //const int *const p3;
    const int *p;
	return 0;
}