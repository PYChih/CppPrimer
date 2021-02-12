#ifndef WORDQUERY_H_
#define WORDQUERY_H_
#include <iostream>
#include <string>
#include "Query_base.h"
#include "TextQuery_QueryResult.h"
class WordQuery : public Query_base {
  friend class Query;
  WordQuery(const std::string &s) : query_word(s) {
    std::cout << "WordQuery::WordQuery(string)" << std::endl;
  }  // NOLINT
  QueryResult eval(const TextQuery &t) const {
    return t.query(query_word);
  }
  std::string rep() const {
    std::cout << "WordQuery::rep()" << std::endl;
    return query_word; }
  std::string query_word;
};
#endif  // WORDQUERY_H_