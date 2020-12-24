/* g++ exercise_3_24.cpp && ./a.out
- 練習3.24: 使用迭代器重做3.3.3的最後一個練習
- 3.3.3: 練習3.20: 將一組整數讀到一個vector中。印出每對相鄰元素的和。更改你的程式，改印出第一與最後一個元素的和，後面接著第二個和倒數第二個的和，依此類推。
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
    int input_int;
    char ch;
    cout << "input a sequence of int ";
    while (cin>>input_int){
        ivec.push_back(input_int);
        ch = getchar();
        if (ch=='\n'){// it's '' not ""
            break;
        }
    }
    // cout sequence of int
    cout<<"your sequence of int : "<<endl;
    for (auto i : ivec){
        cout << i << " ";
    }
    cout<<endl;
    cout<<"sum of each pair"<<endl;
    for (auto i=ivec.begin(); (i+1)!=ivec.end(); ++i){
        cout<<*i + (*i+1)<<" ";
    }
    cout << endl;
    cout<<"sum of first and last"<<endl;
    auto beg = ivec.begin(), end = ivec.end();
    while (beg!=end && beg!=(end-1)){
        cout<<*beg+*(end-1)<<" ";
        beg +=1;
        end -=1;
    }
    cout << endl;
    return 0;
}