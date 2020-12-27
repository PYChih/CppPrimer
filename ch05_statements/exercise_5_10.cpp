//g++ exercise_5_10.cpp && ./a.out
/*
- 練習5.10: 我們實作的母音計數程式有一個問題: 它不會把大寫字母算為母音。寫個能夠將大小寫字母都適切地算為母音的程式，也就是說，你的程式應該將'a'和'A'都累計到aCnt，依此類推。
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
    char ch;
    int cnt=0;
    cout<<"enter a world, ctrl+d to exit"<<endl;
    while(cin>>ch){
        ch = tolower(ch);
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