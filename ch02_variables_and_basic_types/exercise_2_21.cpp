/*
 * 練習2.21: 解釋下列的每個定義。指出那些是不合法的(如果有的話)，並說明原因。
    ```
    int i=0;
    double* dp = &i;
    int *ip = i;
    int *p = &i;
/*
 * g++ exercise_2_21.cpp && ./a.out
 */
#include <iostream>
int main()
{
    int i=0;
    //double* dp = &i; // error: cannot convert ‘int*’ to ‘double*’
    //int *ip = i;
    int *p = &i;
	return 0;
}