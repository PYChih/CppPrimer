/*
- ==練習7.53==: 定義你自己版本的Debug。

 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {}
    constexpr bool any() {return hw || io || other;}
    void set_io(bool b) {io = b;}
    void set_hw(bool b) {hw = b;}
    void set_other(bool b) {hw = b;}
private:
    bool hw; // 除了io錯誤之外的硬體錯誤
    bool io; // io錯誤
    bool other; // 其他錯誤
};

constexpr Debug prod(false); //正式版沒有除錯

int main()
{
    constexpr Debug io_sub(false, true, false); //定義一個constexpr類別的物件叫io_sub，使用constexpr建構器
    //io_sub.any(); // the object has type qualifiers that are not compatible with the member function "Debug::any" -- object type is: const Debug
    //if (io_sub.any()) // 等同於if(true)
    //    cerr << "print appropriate error messages" << endl;
    //if (prod.any()) // 等同於if(false)
    //    cerr << "print an error message" << endl;    

    return 0;
}