#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include "AndQuery.h"
#include "TextQuery_QueryResult.h"
using std::make_shared;
using std::set;
using std::vector;
using std::string;
QueryResult
AndQuery::eval(const TextQuery &text) const {
  auto right = rhs_.eval(text);
  auto left = lhs_.eval(text);
  auto ret_lines = make_shared<set<line_no>>();
  set_intersection(left.begin(), left.end(),
                   right.begin(), right.end(),
                   inserter(*ret_lines, ret_lines->begin()));
  return QueryResult(rep(), ret_lines, left.get_file());
}