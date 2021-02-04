# Exercise_14_31
> Our StrBlobPtr class does not define the copy constructor, assignment operator, or a destructor. Why is that okay?
- StrBlobPtr的成員有: 一個weak_ptr，一個size_t
- 解構器: 他們都有各自的解構器，所以可以用合成的解構器
- 拷貝建構器，他們可以使用合成的拷貝建構器
- 指定運算子，他們可以使用合成的拷貝指定運算子 