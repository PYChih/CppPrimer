# Exercise 11.29:
> What do upper_bound, lower_bound, and equal_range return  
 when you pass them a key that is not in the container?  

- upper_bound: return an iterator to first `>` key, like end()
- lower_bound: return an iterator to first `<=` key, like begin()
- if key no found, upper_bound(k)==lower_bound(k)