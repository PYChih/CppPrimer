# Exercise 12_01
> How many elements do b1 and b2 have at the end of this code?
```
StrBlob b1;
{
    StrBlob b2 = { "a", "an", "the" };
    b1 = b2;
    b2.push_back("about");
}
```
- b1 : 4
- b2 : meaningless : b2 is undefined