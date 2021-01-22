# Exercise 13_35
> 如果Message使用合成版的拷貝控制成員，那會發生什麼事?
- 拷貝: 假設本來有一個Message m1，拷貝建構器是合成的: 新建了一個Message m2，擁有和m1一樣的contents，folders的內容指出有哪些folder存放了m2，可是所有的folder(裡的set)都不會有m2的指針