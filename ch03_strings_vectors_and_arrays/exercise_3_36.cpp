// g++ exercise_3_36.cpp && ./a.out
/*
- 練習3.36: 寫一個程式來比較兩個陣列的相等性。寫一個類似的程式來比較兩個vector。
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

//int main(){// compare vector
//    int arr1[10], arr2[10];
//    vector<int> vec1{1, 2, 3, 4, 5};
//    //vector<int> vec2{1, 2, 3, 4, 5};
//    vector<int> vec2{1, 3, 2, 4, 5};
//    if (vec1==vec2){
//        cout<<"Same vector"<<endl;
//    } else{
//        cout<< "different vector"<< endl;
//    }
//
//    return 0;
//}
int main(){//compare array
    int arr1[3] = {1, 2, 3};
    //int arr2[3] = {1, 2, 3};
    //int arr2[4] = {1, 2, 3, 4};
    int arr2[3] = {2, 1, 3};
    unsigned arr1_size, arr2_size;
    arr1_size = sizeof(arr1)/sizeof(int);
    arr2_size = sizeof(arr2)/sizeof(int);
    cout<<arr1_size<<endl;
    cout<<arr2_size<<endl;
    if (arr1_size==arr2_size){
        cout<<"same size array"<<endl;
        for (int i=0; i<arr1_size; ++i){
            if (arr1[i]==arr2[i]){
                continue;
            }else{
                cout<<"different array"<<endl;
                return 0;
            }
        }
        cout<<"Same array"<<endl;
    } else{
        cout<<"array with different size"<<endl;
    }

}