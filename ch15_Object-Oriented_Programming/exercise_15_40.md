# Exercise 15.40
> In the OrQuery eval function what would happen if its rhs member returned an empty set? What if its lhs member did so? What if both rhs and lhs returned empty sets?
- if rhs return emptyset, right.begin() will equals to right.end()
- if lhs equals to emptyset, ret_lines will be empty
- both emtpy set: return empty set
- 