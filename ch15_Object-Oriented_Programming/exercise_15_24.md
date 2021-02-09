# Exercise 15.24
> What kinds of classes need a virtual destructor? What operations must a virtual destructor perform?
- 有繼承階層架構的類別需要虛擬解構器(基礎類別會把解構器定義成虛擬的)
- 假設有一個基礎類別Base和一個衍生類別Derived，以及一個指向基礎類別的指標p
- 當我們delete p的時候，有可能是delete Derived類別，也有可能是delete Base類別，這時候Derived類別就會需要使用virtual的Base類別解構器