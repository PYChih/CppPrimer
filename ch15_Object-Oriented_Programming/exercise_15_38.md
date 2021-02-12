# Exercise 15.38
> 下列的宣告是合法的嗎?如果不是，為什麼呢?如果是，請解釋該宣告的意義
    ```
    BinaryQuery A = Query("fiery") & Query("bird");
    AndQuery b = Query("fiery") & Query("bird");
    OrQuery c = Query("fiery") & Query("bird");
    ```
- BinaryQuery has pure virtual function eval (abstract class.)
- operator & and operator | return a Query, which can not convert to an And/Or Query object