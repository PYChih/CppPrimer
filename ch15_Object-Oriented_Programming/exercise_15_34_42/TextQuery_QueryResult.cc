#include "TextQuery_QueryResult.h"
TextQuery::TextQuery(std::ifstream &in):
  content(new std::vector<std::string>) {
  std::string line;
  int line_cnt = 0;
  while (getline(in, line)) {
    content->push_back(line);
    std::istringstream record(line);
    std::string word;
    while (record >> word) {
      auto &lines = word2line_set[word];
      if (!lines)
        lines.reset(new std::set<int>);
      lines->insert(line_cnt);
    }
    ++line_cnt;
    }
}
QueryResult TextQuery::query(const std::string &word) const {
  static std::shared_ptr<std::set<int>> nodata(new std::set<int>);
  auto it = word2line_set.find(word);
  if (it == word2line_set.end()) {
      QueryResult qr(word, nodata, content);
      return qr;
  } else {
      QueryResult qr(word, it->second, content);
      return qr;
  }
}
std::string make_plural(int word_cnt, const std::string &word,
                   const std::string &ending) {
  return (word_cnt > 1) ? word + ending : word;
                                 }
std::ostream &print(std::ostream &os, const QueryResult &qr) {
  os << qr.word << " occur " << (*qr.line_set).size()
     << make_plural((*qr.line_set).size(), " time")
     << std::endl;
  for (auto i : *qr.line_set) {
      os << "(line " << i+1 << ") "
         << (*qr.content_ptr)[i] << std::endl;
  }
  return os;
}
std::shared_ptr<std::vector<std::string>> QueryResult::get_file() {
  return content_ptr;
}
std::set<int>::iterator QueryResult::begin() {
  return line_set->begin();
}
std::set<int>::iterator QueryResult::end() {
  return line_set->end();
}
