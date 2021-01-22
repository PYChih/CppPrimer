#ifndef CH12_DYNAMIC_MEMORY_EXERCISE_12_29_H_
#define CH12_DYNAMIC_MEMORY_EXERCISE_12_29_H_
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::set;
using std::map;
using std::endl;
class QueryResult;
class TextQuery {
  friend QueryResult;
 public:
  TextQuery(ifstream& in);  // NOLINT
  QueryResult query(const string &word);
 private:
  vector<string> content;
  map<string, set<int>> word2line_set;
};
class QueryResult {
  friend ostream& print(ostream &os, const QueryResult& qr);
 public:
  QueryResult() = default;
  QueryResult(string s, int wc) : word(s), word_cnt(wc) { }
  QueryResult(string s, set<int> line_num, vector<string>* tq) :
      word(s), line_set(line_num),
      word_cnt(line_num.size()), content_ptr(tq) { }
 private:
  int word_cnt;
  string word;
  set<int> line_set;
  vector<string>* content_ptr;
};
TextQuery::TextQuery(ifstream &in) {
  string line;
  int line_cnt = 0;
  while (getline(in, line)) {
    content.push_back(line);
    istringstream record(line);
    string word;
    while (record >> word) {
      word2line_set[word].insert(line_cnt);
    }
    ++line_cnt;
    }
}
QueryResult TextQuery::query(const string &word) {
  auto it = word2line_set.find(word);
  if (it == word2line_set.end()) {
      QueryResult qr(word, 0);
      return qr;
  } else {
      QueryResult qr(word, it->second, &content);
      return qr;
  }
}
ostream& print(ostream &os, const QueryResult &qr) {
  if (qr.word_cnt > 0) {
    os << qr.word << " occur " << qr.word_cnt << " times" << endl;
    for (auto i : qr.line_set) {
      os << "(line " <<  i << ") ";
      os << (*(qr.content_ptr))[i] << endl;
    }
  } else {
    os << qr.word << " no found " << endl;
  }
  return os;
}
#endif  // CH12_DYNAMIC_MEMORY_EXERCISE_12_29_H_
