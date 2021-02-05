// Exercise 14_34
//  Define a function-object class to perform an if-then-else operation:
//  The call operator for this class should take three parameters.
//  It should test its first parameter and if that test succeeds,
//  it should return its second parameter;
//  otherwise, it should return its third parameter.
#include <iostream>
#include "exercise_14_34.h"  // NOLINT
int IfThenElse::operator()(int v1, int v2, int v3) {
  val1 = v1;
  val2 = v2;
  val3 = v3;
  return val1 ? val2 : val3;
}
int main() {
  IfThenElse ite;
  ite = IfThenElse();
  std::cout << ite(1, 2, 3) << ite(0, 2, 3) << std::endl;
  std::cout << IfThenElse()(1, 2, 3) << std::endl;
}