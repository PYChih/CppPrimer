//g++ learn_iterator.cpp && ./a.out
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
// 3.4.1 change string to first upper
    string s("some string");
    /*
    if (s.begin() != s.end()){
        auto it = s.begin();
        *it = toupper(*it);
    }
     */
    /*
    for (auto it = s.begin(); it !=s.end() && !isspace(*it); ++it){
        *it = toupper(*it);
    }
    cout<<s<<endl;
     */
    //vector<int> v;
    //const vector<int> cv;
    //auto it1 = v.begin(); // it1 has type vector<int>::iterator
    //auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
    //
    /*
    vector<string> text;
    for (auto it = text.cbegin();
         it != text.cend() && !it->empty(); ++it)
         cout<<*it<<endl;
     */
    return 0;
}