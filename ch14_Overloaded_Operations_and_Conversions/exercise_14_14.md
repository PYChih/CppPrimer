# Exercise 14.14
> Why do you think it is more efficient to define operator+ to call operator+= rather than the other way around?
- +=會直接拿繫結的rhs來加
- operator+通常需要在函式裡面造一個臨時變量