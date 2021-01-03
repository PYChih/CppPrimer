/*
- 練習7.58: 如果有的話，下列哪個static資料成員宣告和定義是錯的?請解釋原因。
 */

#include "example.h"
#include <iostream>
#include <string>

double Example::rate=20;
int main()
{
    double i = Example::rate;
    cout<<i<<endl;
    //vector<double> Example::vec;
    return 0;
}