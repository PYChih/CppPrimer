/*
- 練習9.14: 寫一個程式來將一個list中的元素指定給一個vector，其中的list由char*指標組成，這些指標指向C-style的字元字串，而vector則是由string組成。
 */
#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<string>
using std::vector;
using std::string;
using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;

int main(){
    list<const char *> slist = {"hello", "world", "!"};
    vector<string> svec;
    svec.assign(slist.begin(), slist.end());

    return 0;
}