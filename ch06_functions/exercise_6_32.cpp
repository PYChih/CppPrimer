/*
- 練習6.32: 只出下列的函式是否合法。若是，解釋為何如此；如果不是，更正所有的錯誤並解釋之。
```
int &get(int *array, int index) {return array[index];}
int main() {
    int ia[10];
    for (int i = 0; i!=10; ++i)
        get(ia, i) = i;
}
```
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int &get(int *array, int index) {return array[index];} // 下標總是回傳參考喔
int main() {
    int ia[10]; // ia是一個有十個int的陣列
    for (int i = 0; i!=10; ++i){
        get(ia, i) = i;
    }

    for (int i=0; i!=10; ++i){
        cout<<ia[i]<<endl;
    }
}