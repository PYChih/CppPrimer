// Exercise 11.26:
// What type can be used to subscript a map? What type does the subscript
//  operator return? Give a concrete example—that is, define a map and then
//  write the types that can be used to subscript the map and the type that
//  would be returned from the subscript operator.
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int, string> imapstr;
    int i = 1;
    string s = "i'm return type";
    string r;
    // use int to subscript a map
    // will return a lvalue with mapped_type?
    r = imapstr[i];
    cout<<r<<endl;
    imapstr[i] = s;
    cout<<imapstr[i]<<endl;
    return 0;
}
