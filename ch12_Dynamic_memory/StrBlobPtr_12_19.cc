#include "StrBlobPtr_12_19.h"
using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::initializer_list;
StrBlob::StrBlob()
    : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il)
    : data(make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i, const string &msg) const {
  if (i >= data->size())
    throw std::out_of_range(msg);
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
shared_ptr<vector<string>> StrBlobPtr::check(
    std::size_t sz, const string &msg) const {
  shared_ptr<vector<string>> sp = data_wp.lock();
  if (!sp) {
    throw std::runtime_error("unbound StrBlobPtr");
  }
  if (sz >= sp->size()) {
    throw std::out_of_range(msg);
  }
  return sp;
}
string &StrBlobPtr::deref() const {
  shared_ptr<vector<string>> sp = check(curr, "dereference past end");
  return (*sp)[curr];
}
StrBlobPtr &StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}
StrBlobPtr StrBlob::begin() {
  return StrBlobPtr(*this, 0);
}
StrBlobPtr StrBlob::end() {
  return StrBlobPtr(*this, data->size());
}