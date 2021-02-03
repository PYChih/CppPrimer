# Exercise_12_21.md
> We could have written StrBlobPtr’s deref member as follows:
```
std::string &deref() const { 
  return (*check(curr, "dereference past end"))[curr]; 
}
```
>Which version do you think is better and why?
- original: readable