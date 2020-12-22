/*
練習2.39: 編譯下列程式，看看你如果忘了類別定義後的分號，會發生什麼事。記住這種訊息以便未來參考。
error: expected ‘;’ after struct definition
```
// struct Foo {  empty  } //注意: 沒有分號
int main()
{
    return 0;
}
```
 */
/*
 * g++ exercise_2_39.cpp && ./a.out
 */
struct Foo {  /*empty*/  } //注意: 沒有分號
int main()
{
    return 0;
}