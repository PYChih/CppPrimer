/*
練習2.33: 使用本結的變數定義，判斷下列這些指定式各會發生什麼事:
```
a = 42;
b = 42;
c = 42;
d = 42;
e = 42;
g = 42;
```
 */
/*
 * g++ exercise_2_33.cpp && ./a.out
 */
#include <iostream>
int main()
{
    int i = 0, &r = i;
    auto a = r;
    const int ci=i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    a = 42;
    std::cout<<"a value: "<<a<<std::endl;
    b = 42;
    std::cout<<"b value: "<<b<<std::endl;
    c = 42;
    std::cout<<"c value: "<<c<<std::endl;
    //d = 42; //error: invalid conversion from ‘int’ to ‘int*’
    //e = 42; // error: invalid conversion from ‘int’ to ‘const int*’
    //g = 42; //error: assignment of read-only reference ‘g’
	return 0;
}