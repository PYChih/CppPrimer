# Exercise_14_01
> In what ways does an overloaded operator differ from a built-in operator? 
> In what ways are overloaded operators the same as the built-in operators?
- 不同:
    - 可以直接呼叫重載的運算子
    - 重載的運算子至少有一個型別是類別
    - 估算順序(逗號)短路運算(&&和||)沒有保留在重載算子
- 同:
    - 重載和內建運算子的優先級相同
    - 參數數目相同(二元、一元)