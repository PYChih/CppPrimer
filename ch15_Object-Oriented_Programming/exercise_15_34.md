# Exercise 15.34
> For the expression built in Figure 15.3
> a: list the constructors executed in processing that expression.
> b: list the calls to rep that are made from `cout << q`
> c: list the calls to eval made from `q.eval()`  
>`Query q = Query("fiery") & Query("bird") | Query("wind");`
- a
1. construct Query("fiery")
  - Query:Query(string)
    - WordQuery(string)
2. construct Query("bird")
    - Query:Query(string)
      - WordQuery(string)
3. operator&
   - AndQuery:AndQuery(lhs, rhs)
     - BinaryQuery(lhs, rhs, "&")
       - Query:Query(shared_ptr query)
         - `shared_ptr<query_base>`
       - Query:Query(shared_ptr query)
4. construct Query("wind")
    - Query:Query(string)
      - WordQuery(string)
5. 
   - OrQuery:OrQuery(lhs, rhs)
     - BinaryQuery(lhs, rhs, "&")
       - Query:Query(shared_ptr query)
         - `shared_ptr<query_base>`
       - Query:Query(shared_ptr query)
- b `cout << q`
- call `operator<<`:
  - call query.rep()
    - call a shared_ptr->rep, shared_ptr point to OrQuery
      - call binaryquery's rep (lhs_.rep + opSym + rhs_.rep)
        - call query's rep (lhs)
          - call word query's rep 
        - call query's rep (rhs)
          - call word query's rep
- c q.eval
  - q->eval
    - OrQuery's eval but not been defined yet.