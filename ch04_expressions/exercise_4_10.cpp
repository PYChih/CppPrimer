//g++ exercise_4_10.cpp && ./a.out
/*
- 練習4.10: 為一個while迴圈寫出會從標準輸入讀取int並在獨到的值等於42時停止的條件。
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    int number=0;
    cout<<"input a number "<<endl;
    while(cin>>number &&number!=42){
        cout<<"input a number "<<endl;
    }
    cout<<"number equales to 42!!"<<endl;
    return 0;
}