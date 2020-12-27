//g++ exercise_5_11.cpp && ./a.out
/*
- 練習5.11: 修改我們的母音計數程式，讓它也計數讀到的空格、tabs以及newlines。
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    unsigned aCnt = 0, eCnt=0, iCnt=0, oCnt=0, uCnt=0;
    unsigned tabCnt=0, spaceCnt=0, newlinesCnt=0;
    char ch;
    int cnt=0;
    cout<<"enter a txt, ctrl+d to exit"<<endl;
    string str;
    while(cin >> std::noskipws >> ch){
        ch = tolower(ch);
        switch (ch){
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            case '\n':
                ++newlinesCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
        }
    }

    //cout<<"total cnt "<<cnt<<endl;
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n'
         << "Number of space: \t"<<spaceCnt<<'\n'
         << "Number of tab \t"<<tabCnt<<'\n'
         << "Number of newline \t"<<newlinesCnt<<'\n';
    return 0;
}