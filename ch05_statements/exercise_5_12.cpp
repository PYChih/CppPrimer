//g++ exercise_5_12.cpp && ./a.out
/*
- 練習5.12: 修改我們的母音計數程式，讓它計數下列雙字母序列出現的頻率: ff、fl與fi。
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
    unsigned ffCnt=0, fiCnt=0, flCnt=0;
    char ch, prechar;
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
        if (prechar=='f'){
            switch(ch){
                case 'f':
                    ++ffCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
                case 'l':
                    ++flCnt;
                    break;
            }
        }
        prechar=ch;
    }

    //cout<<"total cnt "<<cnt<<endl;
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n'
         << "Number of space: \t"<<spaceCnt<<'\n'
         << "Number of tab \t"<<tabCnt<<'\n'
         << "Number of newline \t"<<newlinesCnt<<'\n'
         << "Number of ff \t"<<ffCnt<<'\n'
         << "Number of fi \t"<<fiCnt<<'\n'
         << "Number of fl \t"<<flCnt<<'\n';
    return 0;
}