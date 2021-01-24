#Exercise 13.41
> 在push_back內的construct呼叫中，為何我們使用後綴遞增?如果用的是前綴遞增，會發生什麼事
- 因為first_free指向的是第一個尚未建構的元素位置，語意上來說就是建構了當前元素之後，first_free移動到下一個