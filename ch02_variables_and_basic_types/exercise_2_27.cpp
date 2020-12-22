/*
 * 練習2.27: 下列哪個初始化是合法的? 請解釋原因。
a. int i = -1, &r = 0; // 一般的參考不可以參考字面值
b. int *const p2 = &i2; //const指標
c. const int i = -1, &r=0;// const int &r=0; 一樣意思
d. const int *const p3 = &i2; // p3是一個const指標，意思是p3不能指別人，再來，const int是對const的指標，它不一定要指const，所以不管i2是不是const這個都可以
e const int *p1 = &i2; //跟上面一樣，對const的指標不一定要指const
f const int &const r2; //哦哦哦，沒有const參考的最佳實踐，這個是因為參考不是對象，所以沒有不變的對象?
g const int i2 = i, &r = i;//const參考不一定要參考const，
 */
/*
 * g++ exercise_2_27.cpp && ./a.out
 */
#include <iostream>
int main()
{
    int i2;
    int i = -1;//, &r = 0;
    int *const p2 = &i2;
    //const int i = -1, &r=0; ///const int &r=0;
    const int *const p3 = &i2;
    const int *p1 = &i2;
    //const int &const r2;
    const int i3 = i, &r = i;

	return 0;
}