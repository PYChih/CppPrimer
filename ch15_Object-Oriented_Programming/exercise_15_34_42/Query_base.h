#ifndef QUERY_BASE_H_
#define QUERY_BASE_H_
#include <string>
#include "TextQuery_QueryResult.h"
class Query_base {
  friend class Query;

 protected:
  using line_no = TextQuery::line_no;  // for eval
  virtual ~Query_base() = default;

 private:
  // eval return QueryResult
  virtual QueryResult eval(const TextQuery&) const = 0;
  virtual std::string rep() const = 0;
};
#endif  // QUERY_BASE_H_