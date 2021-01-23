#ifndef CH12_DYNAMIC_MEMORY_EXERCISE_12_15_H_
#define CH12_DYNAMIC_MEMORY_EXERCISE_12_15_H_
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::cout;
using std::endl;
struct destination;
struct connection;
connection connect(destination*);
void disconnect(connection);
struct destination {
  string location = "home";
};
struct connection {
  connection(destination *d): c_num(c_inc), dest_ptr(d) { ++c_inc; }  // NOLINT
  static int c_inc;
  int c_num;
  destination* dest_ptr;
};
connection connect(destination *d) {
    connection c(d);
    cout << "create connection No: " << c.c_num
         << " connect to: " << (*c.dest_ptr).location << endl;
  return c;
}
void disconnect(connection c) {
  cout << "disconnect No: " << c.c_num
       << " destination : " << (*c.dest_ptr).location << endl;
}
void end_connection(connection *p) {
    disconnect(*p);
}
#endif  // CH12_DYNAMIC_MEMORY_EXERCISE_12_15_H_
