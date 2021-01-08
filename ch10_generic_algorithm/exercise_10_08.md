# Exercise 10.08:
> We said that algorithms do not change the size of the containers over which they operate. Why doesn’t the use of back_inserter invalidate this claim?

Inserters like back_inserter is part of <iterator> rather than <algorithm>.