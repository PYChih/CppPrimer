# Exercise 13.56
> What would happen if we defined sorted as:
  ```
  Foo Foo::sorted() const & {
      Foo ret(*this);
      return ret.sorted();
  }  
  ```
- note: in the function sorted, ret is lvalue
- 無盡調用自己