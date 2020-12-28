/*
- 練習5.25: 改寫前一個練習你寫的程式，使用一個try區塊來catch那個例外。這個catch子句應該印出一個訊息給使用者，並要求他們提供一個新的數字，並重複try裡面的程式碼
g++ exercise_5_25.cpp && ./a.out
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


int main(){
    int int1, int2;
    double result;
    while(cin>>int1>>int2){
        try {
            if (int2==0)
                throw runtime_error("can't devide by zero");
            result = static_cast<double>(int1)/int2;
            cout<< "result "<<result<<endl;
        } catch (runtime_error err){
            cout<<err.what()<<endl;
            cout<<"\n Try Again? Enter y or n"<< endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }

    }



    if (int2==0)
        throw runtime_error("can't devide by zero");
    cout<<static_cast<double>(int1)/int2<<endl;


    return 0;
}