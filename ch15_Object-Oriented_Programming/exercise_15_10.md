# Exercise 15.10
> 回想一下8.1的討論。解釋8.2.1會把一個ifstream傳入Sales_data的read函式的那個程式是如何運作的
- read函式接受一個istream，然後ifstream繼承於istream，我們將ifstream傳遞給接受istream的參考的函數