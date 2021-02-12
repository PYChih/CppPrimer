#ifndef ORQUERY_H_
#define ORQUERY_H_
#include <memory>
#include "BinaryQuery.h"
class OrQuery : public BinaryQuery {
  friend Query operator|(const Query &, const Query &);
  OrQuery(const Query &lhs, const Query &rhs)
      : BinaryQuery(lhs, rhs, "|") {
    std::cout << "OrQuery:OrQuery()" << std::endl;
  }
  QueryResult eval(const TextQuery&) const {
  }
};
inline Query operator|(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
#endif  // ORQUERY_H_