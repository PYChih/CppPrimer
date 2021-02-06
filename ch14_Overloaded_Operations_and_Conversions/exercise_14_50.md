# Exercise 14.50
> Show the possible class-type conversion
> sequences for the initializations of ex1 and ex2.
> Explain whether the initializations are legal or not.
```
struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
// double可以轉成ld
// ld可以轉成double
// ld可以轉乘float
LongDouble ldObj;  // 定義一個ldObj
int ex1 = ldObj;  // 錯誤
// ex1可以由double轉成int
// 也可以由float轉成int
float ex3 = ldObj;
// ldObj轉成float完全匹配
```