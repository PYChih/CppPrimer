/*
 * 練習2.30: 指出下列宣告所宣告的物件是否有頂層或低層的const
```
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
v1 : no
v2 : top
p1 : no
p2 : low
p3 : top and low
r1 : no
r2 : low
 */
/*
 * g++ exercise_2_30.cpp && ./a.out
 */
#include <iostream>
int main()
{
    
	return 0;
}