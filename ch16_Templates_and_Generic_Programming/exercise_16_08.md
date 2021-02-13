# Exercise 16.08
>In the “Key Concept” box on page 108, we noted that as a matter of habit
>C++ programmers prefer using != to using <. Explain the rationale for
>this habit.
- The reason is that more class defines "!=" rather than "<". Doing so can
reduce the number of requirement of the class used with a template class.