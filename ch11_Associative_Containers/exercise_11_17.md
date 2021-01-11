# Exercise 11_17
> Assuming c is a multiset of strings and v is a vector of strings, explain the following calls. Indicate whether each call is legal:
- `copy(v.begin(), v.end(), inserter(c, c.end()));// illegal, key is const`
- `copy(v.begin(), v.end(), back_inserter(c)); // illegal: no push_back in set`
- `copy(c.begin(), c.end(), inserter(v, v.end())); // legal`
- `copy(c.begin(), c.end(), back_inserter(v)); // legal`