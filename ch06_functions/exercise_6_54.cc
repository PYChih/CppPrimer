// Exercise 6.54:
// 為一個函式撰寫宣告，它有兩個int參數，並回傳一個int，然後再宣告一個vector，其元素具有這種函式指標型別
#include<vector>
using std::vector;
int f1(int i1, int i2) { return 0;}
int main() {
  using f1FuncType = decltype(f1);
  vector<f1FuncType*> fvec_decl1;
  typedef int (*funcp) (int, int);  // funcp is a function pointer type
  vector<funcp> fvec_typede1;
  typedef int (func) (int, int);  // func is a function type
  vector<func*> fvec_typede2;
  typedef decltype(f1)* funcp_decl;
  vector<funcp_decl> fvec_decl2;
}
