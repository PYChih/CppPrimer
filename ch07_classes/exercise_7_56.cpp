//- 練習7.56: static類別成員是什麼? static成員的好處是什麼? 它們與一般成員的差異在哪?
//
//- static類別成員是什麼: 宣告的時候帶有static關鍵字的類別成員，static由全體物件共享。
//- 獨立於類別物件的成員，舉例來說，我們有一個銀行帳戶的類別，我們會希望每個這個類別的物件都有一個成員叫基礎匯率，
//可是如果基礎匯率一改變，我們又要對每個物件都去改基礎匯率，顯得有點麻煩，因此可以把基礎匯率定成一個static成員，這樣改一次就可以。
//- static成員的好處: 可以是private，可以針對類別來改動，讓某個變數與類別關聯
//- 與一般成員的差異: 一般成員與某個物件關聯，static成員與某個類別關聯(是說member function不是也是這樣)
//static成員可以當作預設參數，普通成員不能
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
}