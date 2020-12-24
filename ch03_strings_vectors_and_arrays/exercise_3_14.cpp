//g++ exercise_3_14.cpp && ./a.out
/*
- 練習3.14: 寫一個程式從cin讀取一序列的int，並將那些值儲存在一個vector中。
 */
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main(){
    vector<int> ivec;
    char cnt = 'y';
    int i;
    while(cin>>i){
        ivec.push_back(i);
        cout<<" cont y/n?"<<endl;
        cin>>cnt;
        if (cnt!='y'&&cnt!='Y'){
            break;
        }
    }
    for (auto j : ivec)
        cout<<j;
    cout<<endl;
    return 0;
}