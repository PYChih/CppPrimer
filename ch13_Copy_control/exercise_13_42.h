#ifndef CH13_COPY_CONTROL_EXERCISE_13_42_H_
#define CH13_COPY_CONTROL_EXERCISE_13_42_H_
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>
using std::for_each;
using std::allocator;
using std::pair;
using std::initializer_list;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::set;
using std::map;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::make_pair;
class StrVec {
 public:
  StrVec():
    elements(nullptr), first_free(nullptr), cap(nullptr) { }
  StrVec(const StrVec&);  // 4
  StrVec(initializer_list<string> il);  // NOLINT
  StrVec &operator=(const StrVec&);  // 6
  ~StrVec();  // 5
  void push_back(const string&);  // 1
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  string *begin() const { return elements; }
  string *end() const { return first_free; }
  void reserve(size_t sz);
  void resize(size_t n, const string &s_val = "");

 private:
  static allocator<string> alloc;
  void chk_n_alloc() {
    if (size() == capacity()) { reallocate(); }
  }
  pair<string*, string*> alloc_n_copy(const string*, const string*);  // 2
  void free();  // 3
  void reallocate();
  string *elements;
  string *first_free;
  string *cap;
};
void StrVec::push_back(const string& s) {
  chk_n_alloc();
  std::cout << "push_back~" << std::endl;
  alloc.construct(first_free++, s);
}
pair<string*, string*> StrVec::alloc_n_copy(const string *s_beg, const string *s_end) {
  string* new_elements = alloc.allocate(size());
  string* new_first_free = uninitialized_copy(s_beg, s_end, new_elements);
  return make_pair(new_elements, new_first_free);
}
void StrVec::free() {
  if (!elements) {
      for_each(elements, first_free,
              [this](string &rhs) { 
                std::cout << rhs << endl;
                alloc.destroy(&rhs); });
    // while (first_free != elements) {
    //   alloc.destroy(--first_free);
    // }
    alloc.deallocate(elements, cap - elements);
  }
}
StrVec::StrVec(const StrVec& sv) {
  pair<string*, string*> new_data = alloc_n_copy(sv.begin(), sv.end());
  elements = new_data.first;
  first_free = new_data.second;
  cap = new_data.second;
}
StrVec::~StrVec() {
  free();
}
StrVec& StrVec::operator=(const StrVec& sv) {
  pair<string*, string*> new_data = alloc_n_copy(sv.begin(), sv.end());
  free();
  elements = new_data.first;
  first_free = new_data.second;
  cap = new_data.second;
  return *this;
}
void StrVec::reallocate() {
  std::cout << "reallocate !!" << "size " << size() << std::endl; 
  size_t new_capacity = size() ? size() * 2 : 1;
  string* new_element = alloc.allocate(new_capacity);
  string* new_first_free = new_element;
  string* old_element = elements;
  for (size_t i = 0; i != size(); ++i) {
    alloc.construct(new_first_free++, std::move(*old_element++));
  }
  free();
  elements = new_element;
  first_free = new_first_free;
  cap = new_element + new_capacity;
}
void StrVec::reserve(size_t sz) {
  if (capacity() < sz) {
    size_t new_capacity = sz;
    string* new_element = alloc.allocate(new_capacity);
    string* new_first_free = new_element;
    string* old_element = elements;
    for (size_t i = 0; i != size(); ++i) {
      alloc.construct(new_first_free++, std::move(*old_element++));
    }
    free();
    elements = new_element;
    first_free = new_first_free;
    cap = new_element + new_capacity;
  }
}
void StrVec::resize(size_t n, const string &s_val) {
  size_t new_capacity = n;
  string* new_element = alloc.allocate(n);
  string* new_first_free = new_element;
  string* old_element = elements;
  int inc = 0;
  while ((inc < new_capacity) && (inc < size())) {
    alloc.construct(new_first_free++, std::move(*old_element++));
    ++inc;
  }
  if (inc < new_capacity) {
    alloc.construct(new_first_free++, s_val);
    ++inc;
  }
  free();
  elements = new_element;
  first_free = new_first_free;
  cap = new_element + new_capacity;
}
StrVec::StrVec(initializer_list<string> il) {
  size_t new_capacity = il.size();
  string* new_element = alloc.allocate(new_capacity);
  string* new_first_free = new_element;
  for (auto beg = il.begin(); beg != il.end(); ++beg) {
    alloc.construct(new_first_free++, *beg);
  }
  elements = new_element;
  first_free = new_first_free;
  cap = new_element + new_capacity;
}
class QueryResult;
class TextQuery {
  friend QueryResult;
 public:
  TextQuery(ifstream& in);  // NOLINT
  QueryResult query(const string &word);
 private:
  shared_ptr<StrVec> content;
  map<string, shared_ptr<set<int>>> word2line_set;
};
class QueryResult {
  friend ostream& print(ostream &os, const QueryResult& qr);
 public:
  QueryResult() = default;
  QueryResult(const string &s,
      shared_ptr<set<int>> set_sptr,
      shared_ptr<StrVec> f) :
      word(s), line_set(set_sptr), content_ptr(f) { }
  set<int>::iterator begin();
  set<int>::iterator end();
  shared_ptr<StrVec> get_file();
 private:
  string word;
  shared_ptr<set<int>> line_set;
  shared_ptr<StrVec> content_ptr;
};
TextQuery::TextQuery(ifstream &in):
  content(new StrVec) {
  string line;
  int line_cnt = 0;
  while (getline(in, line)) {
    content->push_back(line);
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
         << *((*qr.content_ptr).begin()+i) << endl;
  }
  return os;
}
shared_ptr<StrVec> QueryResult::get_file() {
  return content_ptr;
}
set<int>::iterator QueryResult::begin() {
  return line_set->begin();
}
set<int>::iterator QueryResult::end() {
  return line_set->end();
}
#endif  // CH13_COPY_CONTROL_EXERCISE_13_42_H_
