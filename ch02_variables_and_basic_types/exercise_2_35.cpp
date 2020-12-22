/*
練習2.35: 判斷從下列各個定義推導出來的型別。一旦你找出型別，就寫個程式來看看你是否正確。
```
const int i = 42;
auto j = i;
const auto &k = i;
auto *p = &i;
const auto j2 = i;
&k2 = i;
```
 */
/*
 * g++ exercise_2_35.cpp && ./a.out
 */
#include <iostream>
#include <typeinfo>
int main()
{
	const int i = 42;
	auto j = i;
	//const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;
	std::cout<<typeid(i).name()<<std::endl;
	std::cout<<typeid(j).name()<<std::endl;
	auto &k = i;
	int c = 1;
	k = c;
	// i是const int
	// j是普通int (頂層int丟棄)
	// k是const int的參考，所以k有型別const int&
	// p放了i的位子，所以p有型別const int*
	// j2是const int
	// k2是const int&
	return 0;
}