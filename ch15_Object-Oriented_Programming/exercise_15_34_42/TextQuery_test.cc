// Exercise 12.33
//  In Chapter 15 we’ll extend our query system
//  and will need some additional members in the QueryResult class.
//  Add members named [begin] and [end]
//  that return iterators into the set of line numbers
//  returned by a given query, and a member named [get_file] that
//  returns a shared_ptr to the file in the QueryResult object.
//   Exercise 12.32
//    Rewrite the TextQuery and QueryResult classes to use a StrBlob
//    instead of a vector<string> to hold the input file.
//   Exercise 12.30
//    write your own versions of these classes.
//   Exercise 12.29
//    We could have written the loop to manage the interaction
//    with the user as a do while loop. Rewrite the loop
//    to use a do while. Explain which version you prefer and why.
// g++ -c TextQuery_QueryResult.cc TextQuery_test.cc

#include "TextQuery_QueryResult.h"  // NOLINT
using std::cout;
using std::cin;
using std::string;
using std::endl;
void runQueries(std::ifstream &in) {
    TextQuery tq(in);
    // while (true) {
    //     cout << "enter word to look for, or q to quit : " << endl;
    //     string s;
    //     if (!(cin >> s) || s == "q") break;
    //     print(cout, tq.query(s));
    // }
    do {
        cout << "enter word to look for, or q to quit : " << endl;
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s));
        QueryResult qr = tq.query(s);
        auto beg = qr.begin();
        cout << "line no: ";
        while (beg != qr.end()) {
            cout << *beg+1 << " ";
            ++beg;
        }
        cout << endl;
    } while (true);
}
int main() {
    std::ifstream in("../data/test.txt");
    runQueries(in);
    return 0;
}
