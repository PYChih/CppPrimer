#ifndef CH12_DYNAMIC_MEMORY_EXERCISE_12_32_H_
#define CH12_DYNAMIC_MEMORY_EXERCISE_12_32_H_
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <initializer_list>
#include <exception>
using std::initializer_list;
using std::make_shared;
using std::weak_ptr;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::set;
using std::map;
using std::endl;
using std::shared_ptr;
class StrBlobPtr;
class ConstStrBlobPtr;
class QueryResult;
ostream& print(ostream &os, const QueryResult &qr);
class StrBlob {
  friend StrBlobPtr;
  friend ConstStrBlobPtr;
  friend ostream& print(ostream &os, const QueryResult &qr);
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
class QueryResult;
class TextQuery {
  friend QueryResult;
 public:
  TextQuery(ifstream& in);  // NOLINT
  QueryResult query(const string &word);
 private:
  StrBlob content;
  map<string, shared_ptr<set<int>>> word2line_set;
};
class QueryResult {
  friend ostream& print(ostream &os, const QueryResult& qr);
 public:
  QueryResult() = default;
  QueryResult(const string &s,
      shared_ptr<set<int>> set_sptr,
      StrBlob f) :
      word(s), line_set(set_sptr), content_ptr(f) { }
 private:
  string word;
  shared_ptr<set<int>> line_set;
  StrBlob content_ptr;
};
TextQuery::TextQuery(ifstream &in) {
  string line;
  int line_cnt = 0;
  while (getline(in, line)) {
    content.push_back(line);
    istringstream record(line);
    string word;
    while (record >> word) {
      auto &lines = word2line_set[word];
      if (!lines)
        lines.reset(new set<int>);
      lines->insert(line_cnt);
    }
    ++line_cnt;
    }
}
QueryResult TextQuery::query(const string &word) {
  static shared_ptr<set<int>> nodata(new set<int>);
  auto it = word2line_set.find(word);
  if (it == word2line_set.end()) {
      QueryResult qr(word, nodata, content);
      return qr;
  } else {
      QueryResult qr(word, it->second, content);
      return qr;
  }
}
string make_plural(int word_cnt, const string &word,
                   const string &ending = "s") {
  return (word_cnt > 1) ? word + ending : word;
                                 }
ostream& print(ostream &os, const QueryResult &qr) {
  os << qr.word << " occur " << (*qr.line_set).size()
     << make_plural((*qr.line_set).size(), " time")
     << endl;
  for (auto i : *qr.line_set) {
      os << "(line " << i+1 << ") "
         << (*(qr.content_ptr.data))[i] << endl;
  }
  return os;
}
#endif  // CH12_DYNAMIC_MEMORY_EXERCISE_12_32_H_
