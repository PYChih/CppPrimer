# Exercise 14.11
> 如果有的話，下列Sales_data的輸入運算子有什麼問題呢?  
> 如果我們提供這個運算子給前一個練習中的資料，會發生什麼事呢?
```
istream &operator>>(istream &in, Sales_data &s) {
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}
```
- 不會檢查讀取失敗的情況，遇到非法值會使用未初始化的double