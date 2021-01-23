#ifndef CH12_DYNAMIC_MEMORY_EXERCISE_12_20_H_
#define CH12_DYNAMIC_MEMORY_EXERCISE_12_20_H_
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
class StrBlobPtr;
class StrBlob {
  friend StrBlobPtr;
 public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);  // NOLINT: this is exercise 12_05
    size_type size() const { return data->size();}
    bool empty() const { return data->empty();}
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;
    StrBlobPtr begin();
    StrBlobPtr end();
 private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):
                data(make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}
string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data-> pop_back();
}
const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}
const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}
class StrBlobPtr {
 public:
  StrBlobPtr(): curr(0) { }
  StrBlobPtr(StrBlob &a, size_t sz):  // NOLINT
    data_wp(a.data), curr(sz) { }
  string& deref() const;
  StrBlobPtr& incr();
 private:
  shared_ptr<vector<string>> check(size_t sz, const string &msg) const;
  weak_ptr<vector<string>> data_wp;
  std::size_t curr;  // current index
};
shared_ptr<vector<string>> StrBlobPtr::check(
  size_t sz, const string &msg) const {
  shared_ptr<vector<string>> sp = data_wp.lock();
  if (!sp) {
    throw std::runtime_error("unbound StrBolbPtr");
  }
  if (sz >= sp->size()) {
      throw std::out_of_range(msg);
  }
  return sp;
  }
string& StrBlobPtr::deref() const {
    shared_ptr<vector<string>> sp = check(curr, "dereference past end");
    return (*sp)[curr];
}
StrBlobPtr& StrBlobPtr::incr() {
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
#endif  // CH12_DYNAMIC_MEMORY_EXERCISE_12_20_H_
