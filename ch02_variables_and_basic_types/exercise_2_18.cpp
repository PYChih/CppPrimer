/*
 * 練習2.18: 寫出程式碼來變更一個指標的值。寫出程式碼來變更該指標所指的值。
/*
 * g++ exercise_2_18.cpp && ./a.out
 */
#include <iostream>
int main()
{
    int val = 10;
    int val2 = 20;
    int *change_pointer=&val;
    std::cout << "current pointer value " << change_pointer << std::endl;
    change_pointer = &val2;
    std::cout << "current pointer value " << change_pointer << std::endl;
    *change_pointer = 30;
    std::cout << "current pointer value " << change_pointer << std::endl;
    std::cout << "after dereference value " << *change_pointer << std::endl;
    std::cout << "current val2 value " << val2 << std::endl;
	return 0;
}