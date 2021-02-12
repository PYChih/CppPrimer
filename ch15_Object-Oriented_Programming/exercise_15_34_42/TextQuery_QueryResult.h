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
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream &in);  // NOLINT
  QueryResult query(const std::string &word) const;
 private:
  std::shared_ptr<std::vector<std::string>> content;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> word2line_set;
};
class QueryResult {
  friend std::ostream &print(std::ostream &os, const QueryResult &qr);
  friend std::ostream &operator<<(std::ostream &os, const QueryResult &qr);
 public:
  using line_no = TextQuery::line_no;
  QueryResult() = default;
  QueryResult(const std::string &s,
      std::shared_ptr<std::set<line_no>> set_sptr,
      std::shared_ptr<std::vector<std::string>> f) :
      word(s), line_set(set_sptr), content_ptr(f) { }
  std::set<line_no>::iterator begin();
  std::set<line_no>::iterator end();
  std::shared_ptr<std::vector<std::string>> get_file();
 private:
  std::string word;
  std::shared_ptr<std::set<line_no>> line_set;
  std::shared_ptr<std::vector<std::string>> content_ptr;
};
std::string make_plural(int word_cnt, const std::string &word,
                   const std::string &ending = "s");
std::ostream &print(std::ostream &os, const QueryResult &qr);
std::ostream &operator<<(std::ostream &os, const QueryResult &qr);
#endif  // TEXTQUERY_QUERYRESULT_H_
