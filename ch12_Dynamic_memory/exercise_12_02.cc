#include "exercise_12_02.h"  // NOLINT
using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il)
    : data(make_shared<vector<string>>()) { }
void StrBlob::check(size_type i, const string &msg) const {
  if (i >= data->size()) {
    throw std::out_of_range(msg);
  }
}
string &StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}
string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}
void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}
const string &StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}
const string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}
void StrBlob::push_back(std::string &&t) {
  data->push_back(std::move(t));
}
