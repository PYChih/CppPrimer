// Exercise 13_08
//  Write the assignment operator for the HasPtr class from exercise 13.5 in 13.1.1 (p. 499).
//  As with the copy constructor, your assignment operator should copy the object to which ps points.

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) { }

 private:
   std::string *ps;
   int i;
}