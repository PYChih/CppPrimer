# Exercise 13.57
> What if we defined sorted as:
```
Foo Foo::sorted() const & { return Foo(*this).sorted(); }
```
- ok.
- note return Foo(*this) is rvalue