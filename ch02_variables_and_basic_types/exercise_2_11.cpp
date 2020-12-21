/*
 * 練習2.11: 解釋下列每一個是宣告還是定義:
(a). extern int ix = 1024;
(b) int iy;
(c) extern int iz;
 */
/*
 * g++ exercise_2_11.cpp && ./a.out
 * error: ‘ix’ has both ‘extern’ and initializer

 */
#include <iostream>
#include <string>
int main()
{
    extern int ix = 1024; 
    int iy;
    extern int iz;
    
	return 0;
}