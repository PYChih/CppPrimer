/*
練習2.36: 在下列程式碼中，判斷每個變數的型別，以及程式碼執行完畢之後每個變數的值。
```
int a =3, b=4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
//a 是 int 值4
//b 是 int 值4
//c 是 int 值 4
//d 是 int& 值4
```
 */
/*
 * g++ exercise_2_36.cpp && ./a.out
 */
#include <iostream>
int main()
{
    int a =3, b=4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    std::cout<<"a " << a << std::endl;
    std::cout<<"b " << b << std::endl;
    std::cout<<"c " << c << std::endl;
    std::cout<<"d " << d << std::endl;

	return 0;
}