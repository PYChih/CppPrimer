/*
- 練習9.47: 寫一個程式在"ab2c3d7R4E6"這個string中找出每個數值字元，然後每個字母字元。寫出兩個版本的此程式。第一個應該使用find_first_of，第二個用find_first_not_of
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

void ffov1(string & s, string & abc, string &num)
{
    cout<<"using ffov1"<<endl;
    string::size_type pos=0;
    string str_abc, str_num;
    cout<<"here are find abc :"<<endl;
    while((pos = s.find_first_of(abc, pos))!=string::npos){
        cout<<s[pos]<<" ";
        ++pos;
    }
    cout<<endl;
    pos=0;
    cout<<"here are find num : "<<endl;
    while((pos = s.find_first_of(num, pos))!=string::npos){
        cout<<s[pos]<<" ";
        ++pos;
    }
    cout<<endl;
}

void ffnov2(string & s, string & abc, string &num)
{
    cout<<"using ffnov2"<<endl;
    string::size_type pos=0;
    string str_abc, str_num;
    cout<<"here are find abc :"<<endl;
    string scp = s;
    while((pos = s.find_first_not_of(abc))!=string::npos){
        s.erase(pos, 1);
    }
    cout<<s;
    cout<<endl;
    pos=0;
    cout<<"here are find num : "<<endl;
    s = scp;
    while((pos = s.find_first_not_of(num))!=string::npos){
        s.erase(pos, 1);
        ++pos;
    }
    cout<<s;
    cout<<endl;
}
int main(){
    string s{"ab2c3d7R4E6"};
    string abc{"abcdefghijklmnopqustuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string num{"1234567890"};
    cout<<"s og :"<<s<<endl;
    ffov1(s, abc, num);
    ffnov2(s, abc, num);
    return 0;
}