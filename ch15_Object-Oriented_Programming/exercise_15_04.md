# Exercise 15.04
> Which of the following declarations, if any, are incorrect? Explain why.
```
class Base { ... };
// a
class Derived : public Derivec { ... };
// b
class Derived : private Base { ... };
// c
class Derived : public Base;
// a: 無法從自己衍伸出自己(要繼承要先有定義)
// b: 這是定義不是宣告
// c: 宣告不包含衍生串列
```