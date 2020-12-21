/*
 * 練習2.22: 假設p是對int的一個指標，請解說下列程式碼:
    ```
    if (p) // ...
    if (*p) // ...
    ```
/*
 * g++ exercise_2_22.cpp && ./a.out
 */
#include <iostream>
int main()
{
    int i=0;
    int *p = &i;

	return 0;
}