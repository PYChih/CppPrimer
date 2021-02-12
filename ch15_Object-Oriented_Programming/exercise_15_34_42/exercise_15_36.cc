#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "BinaryQuery.h"
int main() {
  // Query q = Query("fiery");
  std::string s{"fiery"};
  // Query q(s);
  Query q = Query("fiery") & Query("bird") | Query("wind");
  std::cout << q << std::endl;
}