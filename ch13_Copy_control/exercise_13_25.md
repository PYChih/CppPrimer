# Exercise_13_25
> Assume we want to define a version of StrBlob that acts like a value. 
> Also assume that we want to continue to use a shared_ptr 
> so that our StrBlobPtr class can still use a weak_ptr to the vector. 
> Your revised class will need a copy constructor and
> copy-assignment operator but will not need a destructor. 
> Explain what the copy constructor and copy-assignment operators must do. 
> Explain why the class does not need a destructor.

    - 拷貝建構器:
        - StrBlob本來的行為是大家指向同個動態配置的`vector<string>`，改成想要像值一樣的行為的話，拷貝建構的時候要make一個shared_ptr然後用本來指著的`vector<string>`初始化。StrBlobptr就預設的就好
    - 拷貝指定運算子:
        - 開一個新的temp的shared_ptr用本來的值初始化
        - 然後讓本來的shared_ptr.reset(temp)
    - 解構器:
        - 因為shared_ptr不需要delete，所以不需要解構器