//g++ exercise_5_09.cpp && ./a.out
/*
- 練習5.9: 使用一系列的if述句寫一個程式計數從cin讀入的文字中母音的總數
 */
#include<iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    unsigned aCnt = 0, eCnt=0, iCnt=0, oCnt=0, uCnt=0;
    char ch;
    int cnt=0;
    cout<<"enter a world, ctrl+d to exit"<<endl;
    while(cin>>ch){
        if (ch=='a'){
            ++aCnt;
        } else if (ch=='e'){
            ++eCnt;
        } else if (ch=='i'){
            ++iCnt;
        } else if (ch=='o'){
            ++oCnt;
        } else if (ch=='u'){
            ++uCnt;
        }
        ++cnt;
        cout<<ch<<endl;
    }
    cout<<"total cnt "<<cnt<<endl;
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n';
    return 0;
}