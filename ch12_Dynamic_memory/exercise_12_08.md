# Exercise 12.8:
> Explain what if anything is wrong with the following function.
```
bool b() {
    int* p = new int;
    // ...
    return p;
}
```
The p will convert to a bool , which means that the dynamic memory allocated has no chance to be freed. As a result, memory leakage will occur.