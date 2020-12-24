/*g++ exercise_3_25.cpp && ./a.out
- 練習3.25: 使用迭代器來取代下標，改寫3.3.3的成績叢集程式。
假設我們有一組成績，範圍從0到100。我們想要計算有多少成績落入10分為一群的各個叢集。零與100分之間有101個可能的成績。
這些成績可以用11個叢集來表示: 每10分一組的10個叢集，加上滿分100的一個叢集。第一個叢集會計數0到9的成績有幾個，第二個會計數從10到19的，依此類推。最後一個叢及計數有多少個分數達到了100分。
- 測試 輸入:42 65 95 100 30 67 95 76 88 76 83 92 76 93
- 測試 輸出: 0 0 0 1 1 0 2 3 2 4 1
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main(){
    //vector<unsigned> scores;
    //unsigned grade;
    //while(cin >> grade){
    //    if (grade<=100){
    //        ++scores[grade/10]
    //    }
    //}
    vector<unsigned> scores(11, 0);
    char s;
    unsigned grade;
    auto beg = scores.begin();
    while(cin >> grade){
        s = getchar();
        if (grade<=100){
            ++*(beg+grade/10);
        }
        if (s=='\n'){
            break;
        }
    }
    for (auto i : scores){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}