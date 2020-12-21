/*
 * 練習2.9: 解釋下列定義。對那些不合法的定義，請解說何處出錯了，以及如何更正之。
(a). std::cin >> int input_value;
(b). int i = {3.14};
(c). double salary = wage = 999.99;
(d). int i = 3.14;
 */
/*
 * g++ exercise_2_09.cpp && ./a.out
 */
#include <iostream>

int main()
{
    //a
    int input_value=0;
    std::cout << "enter a number:" <<std::endl;
	std::cin >> input_value;
    std::cout << "input value :" << input_value << std::endl;
    //b
    double i = {3.14};
    std::cout << "value i : " << i <<std::endl;
    //c 
    double salary = 99.99, wage = salary;
    int i=3.14;
	return 0;
}