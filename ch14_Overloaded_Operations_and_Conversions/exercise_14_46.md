# Exercise 14.46
> Explain whether defining these Sales_data conversion operators is a good idea and whether they should be explicit.
- 轉換為double有歧異，它有可能可以代表平均售價，也有可能代表revenue
- 轉換為string可能可以不過我沒想到用途
- 兩者都應該定義為explicit