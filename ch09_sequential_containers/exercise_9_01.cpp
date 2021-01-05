/*
- 練習9.1: 對於下列的程式任務，何者是最適當的?一個vector?一個deque或一個list?解釋你的選擇背後的原因。如果沒理由偏好任一種容器，也請解釋為什麼。
```
//a: 讀取固定數目的字詞，在它們被輸入的過程中，以字母順序將它們插入到容器中。我們將在下一章看到，對於這種問題，關聯式容器會是較佳的解法。
// 用list，因為會要隨機插入
//b: 讀取未知數目的字詞。永遠都將新的字詞插入到尾端。從前端移除下一個值。
// 用deque: 頭尾操作
//c: 從一個檔案讀取未知數目個整數。排序這些數字，然後將它們印到標準輸出。
// 用vector: 排序需要頻繁隨機訪問，排除list，不須頭尾操作，因此使用vector
```
 */
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    return 0;
}