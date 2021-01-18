# Exercise_13_02
> Explain why the following declaration is illegal:
``Sales_data::Sales_data(Sales_data rhs);``

- 為什麼拷貝建構器自己的參數必須是參考:
    - 因為函數呼叫的時候，如果不是參考型別，就會呼叫拷貝建構器，所以拷貝建構器自己要是參考