# Exercise 13.52
> Explain in detail what happens in the assignments of the HasPtr objects on page 541. In particular, describe step by step what happens to values of hp, hp2, and of the rhs parameter in the HasPtr assignment operator.

    - 假設hp和hp2都是HasPtr物件
    - `hp = hp2;  // hp2是lvalue，所以hp2的值會被拷貝指定運算子拷貝給hp`
    - `hp = std::move(hp2);  // hp2被std::move轉成了rvalue，因此這邊變成移動指定運算子作用`
    ```
    // HasPtr有的又是移動又是拷貝的指定運算子:
    HasPtr& operator=(HasPtr rhs) {
        swap(*this, rhs);
        return *this;
    }
    ```
    - 當rhs是lvalue，rhs會被拷貝建構器建構
    - 當rhs是lvalue，rhs會被移動建構器建構
    - 無論是哪個建構器，都swap this的指標和rhs的指標，這會讓資料成員的指標逐個被swap(這個swap是我們自己訂的)