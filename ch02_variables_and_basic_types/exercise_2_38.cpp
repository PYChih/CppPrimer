/*
- 練習2.38 : 描述decltype和auto之間型別推導的差異。給出一個運算實例，讓auto和decltype都會推導出相同的型別，以及一個會推導出不同型別的運算實例。
 */
/*
 * g++ exercise_2_38.cpp && ./a.out
 */
#include <iostream>
int main()
{
    int i = 10, *p=&i;
    decltype(*p) a = i ;// a will be int&
    auto q = *p ;// q will be int
    std::cout<<"int q "<<q<<std::endl;
    std::cout<<"int a "<<a<<std::endl;
    i = 11;
    std::cout<<"int q "<<q<<std::endl;
    std::cout<<"int a "<<a<<std::endl;
	return 0;
}