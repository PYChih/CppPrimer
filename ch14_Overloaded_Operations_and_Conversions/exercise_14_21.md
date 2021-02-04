# Exercise 14.21
> Write the Sales_data operators so that + does the actual addition and += calls +. Discuss the disadvantages of this approach compared to the way these operators were defined in 14.3 (p. 560) and 14.4 (p.564).
- 先實作+: 左右運算元以對const的參考傳遞，拷貝建構運算元給temp，將左運算元加上右運算元，回傳Sales_dat的複製，解構Sales_data。再以+實作+=
- 先實作+=: 之後實作+的時候，左右運算元以對const的考傳遞，拷貝建構左運算元給temp，呼叫+=，回Sales_data的複製，解構
- 兩個方法在+的時候步驟一樣，可是+=如果後實作步驟會多