//  Exercise 12.27
//  The TextQuery and QueryResult classes use only capabilities that we have already covered. 
//  Without looking ahead, write your own versions of these classes.
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>

using namespace std;
class QueryResult;
class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> file;
    map<string,
        shared_ptr<set<line_no>>> wm;
};
TextQuery::TextQuery(ifstream &is): file (new vector<string>)
{
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() -1; // current line_no, begin from 0
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word]; // note: lines is a reference of shared_ptr
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

class QueryResult {
friend ostream& print(ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(string s,
                shared_ptr<set<line_no>> p,
                shared_ptr<vector<string>> f):
        sought(s), lines(p), file(f) { }
private:
    string sought; // word for query
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;

};
QueryResult
TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}
ostream &print(ostream & os, const QueryResult &qr)
{
    os << qr.sought << "occurs " << qr.lines->size() << " "
       //<< make_plural(qr.lines->size(), "time", "s") << endl;
        << "time" << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num+1<< ")"
           << *(qr.file->begin() + num) << endl;
    return os;
}