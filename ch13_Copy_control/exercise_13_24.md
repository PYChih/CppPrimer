# Exercise 13.24
> What would happen if the version of HasPtr in this section didn’t define a destructor? What if HasPtr didn’t define the copy constructor?
    - 解構器: 沒定義的話動態配置的string不會被刪除喔
    - 拷貝建構器: 那編譯器會幫我們合成一個，行為會是去拷貝*ps指的位置，那有發生呼叫解構器的時候就有可能重複刪除同一個動態配置的記憶體，結果就會未定義