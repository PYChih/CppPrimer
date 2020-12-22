/*
 * 練習2.32: 下列程式碼是否合法? 若非，你要如何讓它變得合法?
```
int null = 0, *p = null;
```
 */
/*
 * g++ exercise_2_32.cpp && ./a.out
 */
#include <iostream>
int main()
{
    //int null = 0, *p = &null;
    int *p = nullptr;
	return 0;
}