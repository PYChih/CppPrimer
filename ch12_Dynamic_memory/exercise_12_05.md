# Exercise 12.5:
> We did not make the constructor that takes an initializer_list explicit (7.5.4, p. 296). Discuss the pros and cons of this design choice.

Pros

The compiler will not use this constructor in an automatic conversion.
We can realize clearly which class we have used.
Cons

We always uses the constructor to construct a temporary StrBlob object.
cannot use the copy form of initialization with an explicit constructor. not easy to use.