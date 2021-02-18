# Exercise 16.18
> Explain each of the following function template declarations and identify
> whether any are illegal. Correct each error that you find.
```
// a
template <typename T, U, typename V> void f1(T, U, V);
                      ^^
                      typename U
// b
template <typename T> T f2(int &T);
                           ^^^^^^^
                           int &t
// c
inline template <typename T> T foo(T, unsigned int*);
^^^^^^^ inline must be after template
// d
template <typename T> f4(T, T);
                     ^^^ no return type
// e
typedef char Ctype;
            ^^^^^^^ the template declatation below hides this typedef
template <typename Ctype> Ctype f5(Ctype a);
```