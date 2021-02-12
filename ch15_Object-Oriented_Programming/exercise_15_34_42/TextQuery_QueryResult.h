#ifndef TEXTQUERY_QUERYRESULT_H_
#define TEXTQUERY_QUERYRESULT_H_
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
class QueryResult;
class TextQuery {
  friend QueryResult;

 public:
  TextQuery(std::ifstream &in);  // NOLINT
  QueryResult query(const std::string &word) const;
 private:
  std::shared_ptr<std::vector<std::string>> content;
  std::map<std::string, std::shared_ptr<std::set<int>>> word2line_set;
};
class QueryResult {
  friend std::ostream &print(std::ostream &os, const QueryResult &qr);
 public:
  QueryResult() = default;
  QueryResult(const std::string &s,
      std::shared_ptr<std::set<int>> set_sptr,
      std::shared_ptr<std::vector<std::string>> f) :
      word(s), line_set(set_sptr), content_ptr(f) { }
  std::set<int>::iterator begin();
  std::set<int>::iterator end();
  std::shared_ptr<std::vector<std::string>> get_file();
 private:
  std::string word;
  std::shared_ptr<std::set<int>> line_set;
  std::shared_ptr<std::vector<std::string>> content_ptr;
};
std::string make_plural(int word_cnt, const std::string &word,
                   const std::string &ending = "s");
std::ostream &print(std::ostream &os, const QueryResult &qr);
#endif  // TEXTQUERY_QUERYRESULT_H_
