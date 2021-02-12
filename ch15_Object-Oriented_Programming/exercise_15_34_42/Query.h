#ifndef QUERY_H_
#define QUERY_H_
#include <iostream>
#include <string>
#include <memory>
#include "WordQuery.h"
#include "Query_base.h"
#include "TextQuery_QueryResult.h"
class Query {
  friend Query operator~(const Query &);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);

 public:
  Query(const std::string &s) : q(new WordQuery(s)) {  // NOLINT
    std::cout << "Query::Query(string)" << std::endl;
  }  // NOLINT
  QueryResult eval(const TextQuery &t) const {
    return q->eval(t);
  }
  std::string rep() const {
    std::cout << "Query::rep()" << std::endl;
    return q->rep(); }

 private:
  Query(std::shared_ptr<Query_base> query) : q(query) {  // NOLINT
    std::cout << "Query::Query(shared_prt<Query_base>)" << std::endl;
  }
  std::shared_ptr<Query_base> q;
};
std::ostream &operator<<(std::ostream &os, const Query &query) {
  return os << query.rep();
}
Query operator~(const Query &);
#endif  // QUERY_H_