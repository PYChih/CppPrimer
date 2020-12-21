/*
 * 練習2.16: 如果有的話，下列哪個指定是無效的? 如果是有效的，請解釋原因。
int i=0, &r1 = i; double d = 0, &r2 = d;
(a) r2 = 3.14159;
(b) r2 = r1;
(c) i = r2;
(d) r1 = d;

/*
 * g++ exercise_2_16.cpp && ./a.out
 */
#include <iostream>
#include <string>
int main()
{
    int i=0, &r1 = i; double d = 0, &r2 = d;
    r2 = 3.14159;
    std::cout << "d : " << d << std::endl;
    r2 = r1;
    std::cout << " r2 :" << r2 << std::endl;
    i = r2;
    std::cout << " i :" << i << std::endl;
    r1 = d;
    std::cout << " r1 :" << r1 << std::endl;
	return 0;
}