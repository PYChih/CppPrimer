//g++ exercise_3_16.cpp && ./a.out
/*
- 練習3.16: 寫出一個程式印出練習3.13中那些vector的大小與內容。檢查你對於那個練習的解答是否正確。若非如此，重新研讀3.3.1值到你了解為何出錯為止
a. vector<int> v1;// 0個int...
b. vector<int> v2(10); // 10個0
c. vector<int> v3(10, 42);// 10個42
d. vector<int> v4{10};// 一個10
e. vector<int> v5{10, 42};// 兩個，10跟42
f. vector<string> v6 {10};// 10個空字串
g. vector<string> v7{10, "hi"};// 10個hi
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
    vector<int> v1;// 0個int...
    vector<int> v2(10); // 10個0
    vector<int> v3(10, 42);// 10個42
    vector<int> v4{10};// 一個10
    vector<int> v5{10, 42};// 兩個，10跟42
    vector<string> v6 {10};// 10個空字串
    vector<string> v7{10, "hi"};// 10個hi
    cout << "size of v1:" << v1.size()<<endl;
    cout << "size of v2:" << v2.size()<<endl;
    cout << "size of v3:" << v3.size()<<endl;
    cout << "size of v4:" << v4.size()<<endl;
    cout << "size of v5:" << v5.size()<<endl;
    cout << "size of v6:" << v6.size()<<endl;
    cout << "size of v7:" << v7.size()<<endl;
	cout << "v1 content: ";
	for (auto i : v1)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v2 content: ";
	for (auto i : v2)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v3 content: ";
	for (auto i : v3)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v4 content: ";
	for (auto i : v4)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v5 content: ";
	for (auto i : v5)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v6 content: ";
	for (auto i : v6)
	{
		cout << i << " , ";
	}
	cout << endl;

	cout << "v7 content: ";
	for (auto i : v7)
	{
		cout << i << " , ";
	}
	cout << endl;
    return 0;
}