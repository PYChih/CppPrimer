// Exercise 15.39:
// Implement the Query and Query_base classes. Test your application by
// evaluating and printing a query such as the one in Figure 15.3 (p. 638).
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "TextQuery_QueryResult.h"
#include "Query.h"
int main() {
  std::ifstream file("../data/test.txt");
  TextQuery tQuery(file);
  Query q = Query("fiery");
  std::cout << q.rep() << std::endl;
  std::cout << q.eval(tQuery);
  QueryResult qr = q.eval(tQuery);
}
