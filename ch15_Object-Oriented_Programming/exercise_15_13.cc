#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
class base {
 public:
  base() = default;
  base(const std::string &s) : basename(s) { }  // NOLINT
  string name() { return basename; }
  virtual void print(std::ostream &os) { os << basename; }
  virtual ~base() = default;
 private:
  string basename;
};
class derived : public base {
 public:
  derived() = default;
  derived(const std::string &s) : base(s), i(0) { }  // NOLINT
  ~derived() = default;
  void print(std::ostream &os) {
    base::print(os);
    os << " " << i;
  }
 private:
  int i;
};
int main() {
  base b("I'm base");
  derived d("I'm derived");
  b.print(cout);
  cout << endl;
  d.print(cout);
  cout << endl;
}