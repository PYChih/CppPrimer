#ifndef BINARYQUERY_H_
#define BINARYQUERY_H_
#include <string>
#include <iostream>
#include "Query.h"
class BinaryQuery: public Query_base {
 protected:
  BinaryQuery(const Query &lhs, const Query &rhs,
              std::string s) : lhs_(lhs), rhs_(rhs), opSym(s) {
    std::cout << "BinaryQuery::BinaryQuery()" << std::endl;
  }
  std::string rep() const { 
    std::cout << "BinaryQuery::rep()" << std::endl;
    return "(" + lhs_.rep() + " "
                                       + opSym + " "
                                       + rhs_.rep() + ")"; }
  Query lhs_;
  Query rhs_;
  std::string opSym;
};
#endif  // BINARYQUERY_H_