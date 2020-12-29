/*
- 練習6.35: 對factorial的呼叫中，為什麼我們傳入val - 1 而非val--?
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int factorial(int val)
{
    if (val>1)
        return factorial(val-1)*val;
    return 1;
}
int main() 
{
    factorial(10);
    //cout<<recfac(5)<<endl;

}