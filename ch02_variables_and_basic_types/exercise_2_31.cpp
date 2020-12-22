/*
 * 練習2.31: 給定上一個練習的宣告，請判斷下列的指定是否合法。解釋每個例子中頂層或低層const是如何套用的。
r1 = v2; //r1參考v1，v1是個int，現在把v2的值給r1，v2是個const int，本身是頂層const，沒毛病
p1 = p2; //p1是指向int的指標，指的人是v1，v1是個普通的int，p2是指向const int的指標，這個const是低層，所以會影響p1，然後因為p1是個普通指標，普通指標沒辦法拿const int，因為拿了就可以改
p2 = p1;
p1 = p3;
p2 = p3;
 */
/*
 * g++ exercise_2_31.cpp && ./a.out
 */
#include <iostream>
int main()
{
    int i;
    const int v2 = 0; int v1 = v2;
    int *p1 = &v1, &r1 = v1;
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;
    r1 = v2;
    //p1 = p2;
    p2 = p1;
    //p1 = p3;
    p2 = p3;
	return 0;
}