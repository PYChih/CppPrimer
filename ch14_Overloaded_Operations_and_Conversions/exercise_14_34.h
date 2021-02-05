#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_EXERCISE_14_34_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_EXERCISE_14_34_H_
class IfThenElse {
 public:
  IfThenElse() : val1(0), val2(0), val3(0) { }
  IfThenElse(int v1, int v2, int v3) : val1(v1), val2(v2),
      val3(v3) { }
  int operator()(int v1 = 0, int v2 = 0, int v3 = 0);
 private:
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
};
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_EXERCISE_14_34_H_