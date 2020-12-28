/*
- 練習6.15: 解釋find_char的每個參數之型別背後的原因。
特別是，為什麼s是對const的一個參考，但occurs卻是一個普通的參考? 
為什麼這些參數是參考，但char參數c卻不是?
如果我們讓s是一個普通的參考，可能會發生什麼事?
如果讓occurs是對const的一個參考會怎樣呢?
    1. 為什麼s是對const的一個參考?因為我們不想動到s，反過來說，我們希望改動occurs
    2. 為什麼這些參數是參考但char參數c卻不是?因為string可大可小，我們希望避免拷貝string，char似乎沒差
    3. 如果我們讓s是一個普通的參考，可能會發生什麼事?平常沒事，不小心改到有事
    4. 如果讓occurs是對const的一個參考會怎樣呢? 對const的參考代表我們沒辦法從參考去改到本來的值，這個函式就錯了。 
 */
#include<iostream>
#include <string>

using namespace std;

int main(){
    return 0;
}