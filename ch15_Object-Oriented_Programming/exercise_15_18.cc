// Exercise 15.18
//  Given the classes from page 612 and page 613,
//  and assuming each object has the type specified in the comments,
//  determine which of these assignments are legal.
//  Explain why those that are illegal aren’t allowed:

class Base {
 public:
  void pub_mem();
 protected:
  int prot_mem;
 private:
  char priv_mem;
};
struct Pub_Derv : public Base {
  int f() { return prot_mem; }
  // char g() { return priv_mem; }  // private inaccessible
};
struct Priv_Derv : private Base {
  int f1() const { return prot_mem; }
};
struct Prot_Derv : protected Base {
  int fp() const { return prot_mem; }
};
struct Derived_from_Public : public Pub_Derv {
  int use_base() { return prot_mem; }
};
struct Derived_from_Private : public Priv_Derv {
  // int use_base() { return prot_mem; }  //private derived: inaccessible
};
struct Derived_from_Protected : public Prot_Derv {
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