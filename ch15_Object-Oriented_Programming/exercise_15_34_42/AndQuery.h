#ifndef ANDQUERY_H_
#define ANDQUERY_H_
#include <iostream>
#include <memory>
#include "TextQuery_QueryResult.h"
#include "BinaryQuery.h"
class AndQuery : public BinaryQuery {
  friend Query operator&(const Query&, const Query&);
  AndQuery(const Query &lhs, const Query &rhs) :
      BinaryQuery(lhs, rhs, "&") {
        std::cout << "AndQuery::AndQuery()" << std::endl;
  }
  QueryResult eval(const TextQuery &) const;
};
inline Query operator&(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
#endif  // ANDQUERY_H_