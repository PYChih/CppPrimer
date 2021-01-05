/*
- 練習9.6: 下列程式有什麼錯?你會如何更正之?
    ```
    list<int> lst1;
    list<int>::iterator iter1 = 1st1.begin(),
                        iter2 = lst1.end();
    while (iter1 < iter2)
    ```
    ```
    //list的迭代器不支持"<"喔
    //(iter1 != iter2)
    ```
 */
#include<iostream>
#include<list>
using std::list;
using std::cout;
using std::cin;
using std::endl;

int main(){
    list<int> lst1{1, 2, 3, 4, 5};
    list<int>::iterator iter1 = lst1.begin(),
                        iter2 = lst1.end();
    while (iter1 != iter2){
        cout<<"!!!"<<endl;
        ++iter1;
    }

    return 0;
}