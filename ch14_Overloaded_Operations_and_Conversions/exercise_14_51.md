# Exercise 14.51
> 指出呼叫每一個版本的calc所需要的轉換程序(如果有的話)，並解釋最佳的合用函式被選取的原因
```
void calc(int);
void calc(LongDouble);
double dval;
calc(dval);  // 哪個calc?
// calc接受int或LongDouble
// dval是double
// 內建轉換從double到int可以呼叫calc
// 使用者定義轉換double可以轉成LongDouble
```
- best viable function: void calc(int).
- cause class-type conversion is the lowest ranked.
## review the order:
1. exact match
2. const conversion
3. promotion
4. arithmetic or pointer conversion
5. class-type conversion