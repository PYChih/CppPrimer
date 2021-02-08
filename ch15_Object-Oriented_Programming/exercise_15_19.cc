// Exercise 15.19
//  Assume that each of the classes from page 612 and page 613
//  has a member function of the form:
//  void memfcn(Base &b) { b = *this; }
//  For each class, determine whether this function would be legal.
// Base Y
// Pub_Derv : Y
// Priv_Derv : Y
// Prot_Derv : Y
// Derived_from_Public : Y
// Derived_from_Private : N
// Derived_from_Protected : Y
class Base {
 public:
  void pub_mem();
  void memfcn(Base &b) { b = *this; }  // NOLINT
 protected:
  int prot_mem;
 private:
  char priv_mem;
};
struct Pub_Derv : public Base {
  void memfcn(Base &b) { b = *this; }  // NOLINT
  int f() { return prot_mem; }
  // char g() { return priv_mem; }  // private inaccessible
};
struct Priv_Derv : private Base {
  void memfcn(Base &b) { b = *this; }  // NOLINT
  int f1() const { return prot_mem; }
};
struct Prot_Derv : protected Base {
  void memfcn(Base &b) { b = *this; }  // NOLINT
  int fp() const { return prot_mem; }
};
struct Derived_from_Public : public Pub_Derv {
  void memfcn(Base &b) { b = *this; }  // NOLINT
  int use_base() { return prot_mem; }
};
struct Derived_from_Private : public Priv_Derv {
  // conversion to inaccessible base class,
  // base is private for Derived_from_Private
  // void memfcn(Base &b) { b = *this; }  // NOLINT  
  // int use_base() { return prot_mem; }  //private derived: inaccessible
};
struct Derived_from_Protected : public Prot_Derv {
  void memfcn(Base &b) { b = *this; }  // NOLINT
  // ooo
};
int main() {
  Pub_Derv d1;
  Base *p = &d1;  // d1有型別Pub_Derv
  // p會指向d1的基礎類別的部分
  Priv_Derv d2;
  // Base *p = &d2;  // conversion to inaccessible base class is not allowed
  Prot_Derv d3;
  // Base *p = &d3;  // conversion to inaccessible base class is not allowed
  Derived_from_Public dd1;
  p = &dd1;
  Derived_from_Protected dd2;
  // p = &dd2;  // conversion to inaccessible
  Derived_from_Private dd3;
  // p = &dd2;  // conversion to inaccessible
}