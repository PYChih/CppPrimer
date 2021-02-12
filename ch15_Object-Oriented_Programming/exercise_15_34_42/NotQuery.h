#ifndef NOTQUERY_H_
#define NOTQUERY_H_
#include <iostream>
#include <string>
#include <memory>
#include "Query_base.h"
#include "Query.h"
class NotQuery : public Query_base {
  friend Query operator~(const Query &);
  NotQuery(const Query &q) : query(q) {  // NOLINT
    std::cout << "NotQuery::NotQuery(Query)" << std::endl;
  }  // NOLINT
  std::string rep() const {
    std::cout << "NotQuery::rep()" << std::endl;
    return "~(" + query.rep() + ")";
  }
  QueryResult eval(const TextQuery&) const;
  Query query;
};
inline Query operator~(const Query &operand) {
  return std::shared_ptr<Query_base> (new NotQuery(operand));
}
#endif  // NOTQUERY_H_