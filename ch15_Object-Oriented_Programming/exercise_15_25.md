# Exercise 15.25
> Why did we define a default constructor for Disc_quote? What effect, if any, would removing that constructor have on the behavior of Bulk_quote?
- 因為有定義拷貝建構器，所以不會自動合成預設建構器
- 如果沒有預設建構器，Bulk_quote就不會自己合成預設建構器，因為他的基礎類別沒有