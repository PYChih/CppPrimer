// Exercise 12.27
//  The TextQuery and QueryResult classes
//  use only capabilities that we have already covered.
//  Without looking ahead, write your own versions of these classes.

#include "exercise_12_27.h"  // NOLINT
using std::cout;
using std::cin;
void runQueries(ifstream &in) {
    TextQuery tq(in);
    while (true) {
        cout << "enter word to look for, or q to quit : " << endl;
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s));
    }
}
int main() {
    ifstream in("data/google_blog");
    runQueries(in);
    return 0;
}
