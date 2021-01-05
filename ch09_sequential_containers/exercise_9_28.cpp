/*
- 練習9.28: 寫一個函式接受一個``forward_list<string>``，以及兩個額外的string引數。這個函式應該找到第一個string然後緊接著它，將第二個string插入到它後方。如果那第一個string沒找到，那麼就將第二個string插入串列的尾端。
case1:
input forward_list hello !!!
s1: hello
s2: world
output hello world !!!
case2:
input forward_list 
s1: hello
s2: world
output world
 */
#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<string>
#include<forward_list>
using std::forward_list;
using std::vector;
using std::string;
using std::list;
using std::deque;
using std::cout;
using std::cin;
using std::endl;
#include<iterator>
using std::begin;
using std::end;

forward_list<string>& insert_forward_list(forward_list<string> &str_fls, string &s1, string &s2)
{
    auto before_it = str_fls.before_begin();
    auto curr_it = str_fls.begin();
    while (curr_it!=str_fls.end()){
        if (*curr_it==s1){
            str_fls.insert_after(curr_it, s2);
            return str_fls;
        }
        before_it = curr_it;
        ++curr_it;
    }
    str_fls.insert_after((before_it), s2);
    return str_fls;

}

void cout_forward_str(const forward_list<string> &str_fls){
    for (auto i : str_fls){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    //forward_list<string> str_fls{"Hello", "!!!"};
    forward_list<string> str_fls;
    string s1("Hello"), s2("world");
    insert_forward_list(str_fls, s1, s2);
    cout_forward_str(str_fls);
    return 0;
}