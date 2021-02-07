# Exercise 15.1
> What is a virtual member?
- 基礎類別預期衍生類別會覆寫的成員會在宣告前使用virtual關鍵字
- 除了建構器以外的成員都可以是虛擬成員
- 在類別內宣告必須加上virtual關鍵字，類別外的函式定義不能加上virtual關鍵字
- 就算解構器沒做事，也需要定義一個虛函式的解構器