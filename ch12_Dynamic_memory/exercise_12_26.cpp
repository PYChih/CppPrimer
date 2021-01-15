//  Exercise 12.26 
//  Rewrite the program on page 481 using an allocator. 

#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main(){
    int n=10;
    //string *const p = new string[n]; // p is const and p is pointer
    //string s;
    //string *q = p;
    //while (cin >> s && q != p + n)
    //    *q++ = s;
    //const size_t size = q - p;
    //cout<<*p<<endl;
    //delete [] p;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    string s;
    string *q = p; // construct from q
    while (cin >> s && q != p+n){
        alloc.construct(q, s);
        cout<<"construct"<<endl;
        ++q;
    }
    string *r = p;
    while (r!=q){
        cout<<*r<<endl;
        ++r;
    }
    while (q!=p){
        alloc.destroy(--q);
    }

    return 0;
}