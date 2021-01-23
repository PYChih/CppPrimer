#ifndef CH12_DYNAMIC_MEMORY_EXERCISE_12_33_H_
#define CH12_DYNAMIC_MEMORY_EXERCISE_12_33_H_
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
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
class QueryResult;
class TextQuery {
  friend QueryResult;
 public:
  TextQuery(ifstream& in);  // NOLINT
  QueryResult query(const string &word);
 private:
  shared_ptr<vector<string>> content;
  map<string, shared_ptr<set<int>>> word2line_set;
};
class QueryResult {
  friend ostream& print(ostream &os, const QueryResult& qr);
 public:
  QueryResult() = default;
  QueryResult(const string &s,
      shared_ptr<set<int>> set_sptr,
      shared_ptr<vector<string>> f) :
      word(s), line_set(set_sptr), content_ptr(f) { }
  set<int>::iterator begin();
  set<int>::iterator end();
  shared_ptr<vector<string>> get_file();
 private:
  string word;
  shared_ptr<set<int>> line_set;
  shared_ptr<vector<string>> content_ptr;
};
TextQuery::TextQuery(ifstream &in):
  content(new vector<string>) {
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
         << (*qr.content_ptr)[i] << endl;
  }
  return os;
}
shared_ptr<vector<string>> QueryResult::get_file() {
  return content_ptr;
}
set<int>::iterator QueryResult::begin() {
  return line_set->begin();
}
set<int>::iterator QueryResult::end() {
  return line_set->end();
}
#endif  // CH12_DYNAMIC_MEMORY_EXERCISE_12_33_H_
