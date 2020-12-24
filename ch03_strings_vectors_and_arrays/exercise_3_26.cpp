/*g++ exercise_3_26.cpp && ./a.out
- - 練習3.26: 在前面的二元搜尋程式中，為什麼我們寫的是mid = beg + (end - beg) / 2; 而非min = (beg + end) / 2
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
// 3.4.2 binary search
    // sorted text 
    vector<int> ivec = {2, 4, 6, 7, 10, 12, 14, 16, 18, 20};
    int sought = 2;
    //vector<int> ivec = {2, 4, 5, 6};
    auto beg = ivec.begin(), end = ivec.end();
    auto mid = ivec.begin() + (end - beg)/2; //middle point;
    //auto mid = (beg + end) / 2;
    //{2, 4, 5, 6} output 5
    //cout<< *mid <<endl;
    while (mid !=end && *mid != sought){
        cout << "current beg :" << *beg<<endl;
        cout << "current mid :" << *mid << endl;
        cout << "current end -1 :" << *(end-1) << endl;
        if (sought < *mid)
            end = mid;
        else{
            beg = mid + 1;
        }
        mid = beg + (end-beg)/2;
    }
    return 0;
}