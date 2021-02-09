// Exercise 15.23
//  Assuming class D1 on page 620 had intended to override
//  its inherited fcn function, how would you fix that class?
//  Assuming you fixed the class so that fcn matched the definition in Base,
//  how would the calls in that section be resolved?
struct Base {
  int memfcn();
  virtual int fcn();
};
struct Derived : Base {
  int memfcn(int);  // not virtual
};
class D1 : public Base {
 public:
  // int fcn(int);  // not virtual
  // 15.23: d1 want to override
  int fcn();
  virtual void f2();
};
class D2 : public D1 {
 public:
  int fcn(int);
  int fcn();  // override Base
  void f2();  // override
};
int main() {
  Derived d;
  Base b;
  Base bobj;
  D1 d1obj;
  D2 d2obj;
  Base *bp1 = &bobj;
  Base *bp2 = &d1obj;
  Base *bp3 = &d2obj;
  bp1->fcn();  // Base::fcn
  bp2->fcn();  // D1::fcn
  bp3->fcn();  // D2::fcn
  D1 *d1p = &d1obj;
  D2 *d2p = &d2obj;
  // bp2->f2();
  d1p->f2();
  d2p->f2();
  Base *p1 = &d2obj;
  D1 *p2 = &d2obj;
  D2 *p3 = &d2obj;
  // p1->fcn(42);
  // p2->fcn(42);
  p3->fcn(42);
}
