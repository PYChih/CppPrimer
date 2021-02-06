# Exercise 14.52
> 如果有的話，哪個operator+會被選來套用到下列每一個加法運算式?列出候選函式、合用函式，以及每個合用函式的引數適用的型別轉換
```
struct LongDouble {
    // 成員operator+用於說明用途
    // +通常是非成員
    LongDouble operator+(const SmallInt&)
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
LongDouble operator+(LongDouble&, double);
SmallInt si;
LongDouble ld;
ld = si + ld;
ld = ld + si;
```