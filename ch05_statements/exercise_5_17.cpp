/*
- 練習5.17: 給定由int組成的兩個vector，
寫一個程式來判斷其中一個vector是否為另一個的前綴(prefix)。
對於長度不同的vector，比較較小vector的元素數。
舉例來說，若給定分別含有0、1、1與2以及0、1、1、2、3、5、8的兩個vector，你的程式應該回傳true。
g++ exercise_5_17.cpp && ./a.out
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
	vector<int> v1 = {0, 1, 1, 2};
	//vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
	vector<int> v2 = {0, 1, 2, 2, 3, 5, 8};

	auto min_sz = v1.size() < v2.size() ? v1.size() : v2.size();

	bool is_prefix = true;
	for (decltype(min_sz) i = 0; i < min_sz; ++i) {
		if (v1[i] != v2[i]) {
			is_prefix = false;
			break;
		}
	}

	if (is_prefix) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

	return 0;
}