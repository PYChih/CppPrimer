/*
 * - 練習2.29: 使用前一個練習中的變數，請問下列哪個指定是合法? 請解釋原因。
```
a i = ic;
b p1 = p3;
c p1 = &ic;
d p3 = &ic;
e p2 = p1;
f ic = *p3;
```前一個練習
a int i, *const cp;//cp是一個const指標，就是說它指了之後就不能變了，所以一開始要給好
b int *p1, *const p2; //p1是指向int的指標，p2是指向int的const指標，所以p2要init
c const int ic, &r = ic;//ic是一個const int一開始要先給值，r是對一個const int的參考，所以const int &r = ic是可以的，ic要先定義喔，然後管它是不是const都可以
d const int *const p3;//p3是一個const指標，所以一開始要先指著某個人喔
e const int *p//指向const int的指標，不用一開始就先指好
```前一個練習
 */
/*
 * g++ exercise_2_29.cpp && ./a.out
 */
#include <iostream>
int main()
{
    /*
    const int ic = 0;
    int i ;
    i = ic;
     */
    int a = 0;
    int *p1;
    const int *const p3=&a;
    p1 = p3;
	return 0;
}