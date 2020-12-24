//g++ learn_iterator.cpp && ./a.out
#include<iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
// 3.4.1 change string to first upper
    string s("some string");
    /*
    if (s.begin() != s.end()){
        auto it = s.begin();
        *it = toupper(*it);
    }
     */
    /*
    for (auto it = s.begin(); it !=s.end() && !isspace(*it); ++it){
        *it = toupper(*it);
    }
    cout<<s<<endl;
     */
    //vector<int> v;
    //const vector<int> cv;
    //auto it1 = v.begin(); // it1 has type vector<int>::iterator
    //auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
    //
    /*
    vector<string> text;
    for (auto it = text.cbegin();
         it != text.cend() && !it->empty(); ++it)
         cout<<*it<<endl;
     */
// 3.4.2 binary search
    // sorted text 
    vector<int> ivec = {2, 4, 6, 7, 10, 12, 14, 16, 18, 20};
    int sought = 2;
    //vector<int> ivec = {2, 4, 5, 6};
    auto beg = ivec.begin(), end = ivec.end();
    auto mid = ivec.begin() + (end - beg)/2; //middle point;
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