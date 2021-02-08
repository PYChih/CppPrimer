# Exercise 15.14
> 給定來自前一個練習的類別以及下列物件，判斷執行時期被呼叫的函式是哪一個:
```
base bobj;
base *bp1 = &bobj;
base &br1 = bobj;
derived dobj;
base *bp2 = &dobj;
base &br2 = dobj;
// a
bobj.print();
// base
// b
dobj.print();
// derived
// c
bp1->name();
// 指向base的指標
// base
// d
bp2->name();
// 靜態型別是指向base的指標
// 動態型別是指向derived的base部分
// 會印出base的name
// e
br1.print();
// br1是對base的參考
// 呼叫base的print
// f
br2.print();
// br2的靜態型別是對base的參考
// 參考自derived
所以這個print呼叫derived的
```