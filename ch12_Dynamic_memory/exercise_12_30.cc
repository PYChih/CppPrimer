//  Exercise 12.30
//  write your own versions of these classes.
//   Exercise 12.29
//    We could have written the loop to manage the interaction
//    with the user as a do while loop. Rewrite the loop
//    to use a do while. Explain which version you prefer and why.
#include "exercise_12_30.h"  // NOLINT
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
    do {
        cout << "enter word to look for, or q to quit : " << endl;
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s));
    } while (true);
}
int main() {
    ifstream in("data/google_blog");
    runQueries(in);
    return 0;
}
