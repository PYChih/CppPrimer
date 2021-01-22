#ifndef CH13_COPY_CONTROL_EXERCISE_13_19_H_
#define CH13_COPY_CONTROL_EXERCISE_13_19_H_
#include <string>
using std::string;

class Employee {
 public:
  Employee();  // default constructure
  Employee(const string& name); //NOLINT
  Employee(const Employee& ei) : id_(s_increment), name_(ei.name_) { }
  Employee& operator=(const Employee&) {
      id_ = s_increment++;
      return *this;
      }
  int myid() const { return id_; }
 private:
  string name_;
  int id_;
  static int s_increment;
};
Employee::Employee() {
    id_ = s_increment++;
}
Employee::Employee(const string &name) {
    id_ = s_increment++;
    name_ = name;
}

#endif  // CH13_COPY_CONTROL_EXERCISE_13_19_H_
