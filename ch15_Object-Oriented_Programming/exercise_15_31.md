# Exercise 15.31
> Given that s1, s2, s3, and s4 are all strings, determine what objects are created in the following expressions:
```
// a
Query(s1) | Query(s2) & ~ Query(s3);
// b
Query(s1) | (Query(s2) & ~ Query(s3));
// c
(Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
```
- a
  - Query
    - AndQuery
      - NotQuery(s3)
      - OrQuery
        - WordQuery(s1)
        - WordQuery(s2)
- b
  - Query
    - OrQuery
      - AndQuery
        - WordQuery(s2)
        - NotQuery(s3)
      - WordQuery(s1)
- c
  - Query
    - OrQuery
      - AndQuery
        - WordQuery(s1)
        - WordQuery(s2)
      - AndQUery
        - WordQuery(s3)
        - WordQuery(s4)