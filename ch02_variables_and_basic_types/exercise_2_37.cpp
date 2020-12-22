/*
練習2.37 : 指定(assignment)是會產出參考型別的運算實例。型別會是指涉左邊運算元型別的一種參考，也就是說，如果i是一個int，那麼運算式i = x的型別就會是int&。藉由這個知識，判斷這段程式碼中每個變數的型別與值。
```
int a =3, b=4;
decltype(a) c = a;
decltype(a = b) d = a;
```
 */
/*
 * g++ exercise_2_37.cpp && ./a.out
 */
#include <iostream>
int main()
{
    int a =3, b=4;
    decltype(a) c = a;
    decltype(a = b) d = a;
    std::cout<<"a " << a << std::endl;
    std::cout<<"b " << b << std::endl;
    std::cout<<"c " << c << std::endl;
    std::cout<<"d " << d << std::endl;
    //a 是 int 值3
    //b 是 int 值4
    //c 是 int 值3
    //d 是 int& 值3
	return 0;
}