// g++ exercise_3_39.cpp && ./a.out
/*
- 練習3.39: 撰寫一個程式來比較兩個string。現在撰寫一個程式來比較兩個C-style字元字串的值
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

//int main(){
//    string line_1, line_2;
//    cin >> line_1 >> line_2;
//    cout << "print " << line_1 << endl;
//    cout << "print " << line_2 << endl;
//    if (line_1.size()==line_2.size()){
//        cout << " Same size !"<< endl;
//    } else {
//        string::size_type s_1=line_1.size(), s_2=line_2.size();
//        if (s_1>s_2){
//            cout << "line 1 large" << endl;
//        } else {
//            cout << "line 2 large" << endl;
//        }
//    }
//    if (line_1==line_2){
//        cout<< "Same String"<<endl;
//    }
//    return 0;
//}
int main(){
    char ca1[] = "A string example";
    //char ca2[] = "A string example";
    char ca2[] = "A different string";
    //char ca2[] = "a string example";
    char ca1i;
    char ca2i;
    //first we compare size
    if (strlen(ca1)==strlen(ca2)){
        cout<<"same size"<<endl;
        for(unsigned i=0; i<strlen(ca1); ++i){
            ca1i = ca1[i];
            ca2i = ca2[i];
            if (ca1i==ca2i){
                continue;
            } else{
                cout<< "different C-Style String"<<endl;
                return 0;
            }
        }
        cout<<"Same C-Style String"<<endl;
    }else{
        cout<<"different C-Style String"<<endl;
    }
    return 0;
}