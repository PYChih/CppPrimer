# Exercise 13.51
> Although unique_ptrs cannot be copied, in 12.1.5 (p. 471) we wrote a clone function that returned a unique_ptr by value. Explain why that function is legal and how it works.

    - unique_ptr不能拷貝但是可以移動
    - 在function以值回傳時會是rvalue，function外藉由移動指定運算子或移動建構器進行移動