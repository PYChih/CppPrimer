# Exercise 14.53: 
> 給定前面SmallInt的定義，判斷下列加法運算式是否合法
> 如果是，用的是哪個加法運算子呢?如果不是，你會如何變更程式碼，讓它變得合法?
```
class SmallInt {
    friend
    SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int = 0);  // int to SmallInt
    operator int() const { return val; }  // SmallInt to int
private:
    std::size_t val;
};
SmallInt s1;
double d = s1 + 3.14;
```
- 不合法
  1. 3.14可以先轉成int然後轉成SmallInt, 接著使用SmallInt的加法
  2. s1先轉成int然後內建轉成double，使用內建的加法(double)

```
double d = static_cast<int>(s1) + 14;
```