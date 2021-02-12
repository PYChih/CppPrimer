#include <string>
#include <set>
#include "OrQuery.h"
#include "TextQuery_QueryResult.h"
using std::make_shared;
using std::set;
using std::vector;
using std::string;
QueryResult
OrQuery::eval(const TextQuery &text) const {
  auto right = rhs_.eval(text);
  auto left = lhs_.eval(text);
  auto ret_lines =
      make_shared<set<line_no>>(left.begin(), left.end());
  ret_lines->insert(right.begin(), right.end());
  return QueryResult(rep(), ret_lines, left.get_file());
}