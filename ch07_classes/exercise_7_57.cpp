/*
- 練習7.57: 撰寫你自己版本的Account類別。
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate;}
    static void rate(double);
private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();
    static constexpr int period = 30;//period是一個常數運算式
    double daily_tbl[period]; //
};
void Account::rate(double newRate)
{
    interestRate = newRate;
}
double Account::interestRate = initRate();
int main()
{

    return 0;
}