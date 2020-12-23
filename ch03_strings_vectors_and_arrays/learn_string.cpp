//g++ learn_string.cpp && ./a.out

#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
// 3.2.1 define and initial string
    /*
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c'); // s4: cccccccccc
     */
// 3.2.2 read and write string
    /*
    string s;
    cin >> s;
    cout << s << endl;
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << s2 << endl;
    string line;
    while (getline(cin, line))
        if (!line.empty()){
            cout << "print :" << line << endl;
            cout << "num_char :" << line.size() << endl;
        }
     */
// 3.2.3 one char on string
    /*
    string str("some string");
    for (auto c : str){
        cout << c << endl;
    }
     */
    /*
    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s){
        if (ispunct(c))
            ++punct_cnt;
    }
    cout << punct_cnt
         << "punctuation characters in " << s << endl;
     */
    /*
    string s("Hello World!!!");
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;
     */
    /*
    string s("Hello World!!!");
    for (decltype(s.size()) index = 0;
        index !=s.size() && !isspace(s[index]); ++index)
            s[index] = toupper(s[index]);
    cout << s << endl;
     */
    const string hexdigits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 and 15"
          << " separated by spaces. Hit ENTER when finished: "
          << endl;
    string result;
    string::size_type n;
    while (cin >> n)
        if (n < hexdigits.size()){
            result += hexdigits[n];
        } 
    cout << "Your hex number is :" << result << endl;
    return 0;
}