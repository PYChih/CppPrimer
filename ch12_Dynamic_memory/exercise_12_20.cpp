//  Exercise 12.20
//  Write a program that reads an input file a line at a time into
//  a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>
using std::ifstream;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::initializer_list;
using std::out_of_range;
using std::runtime_error;
class StrBlobPtr;
class StrBlob {
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size();}
    bool empty() const { return data->empty();}
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();
    StrBlobPtr begin();
    StrBlobPtr end();
    string& front();
    string& back();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;

};
StrBlob::StrBlob(): data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> il):
                data(make_shared<vector<string>>(il)){}
void StrBlob::check(size_type i, const string &msg) const
{
    if (i>=data->size())
        throw out_of_range(msg);
}
string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}
string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data-> pop_back();
}
class StrBlobPtr{
public:
    StrBlobPtr(): curr(0) { } // 預設建構器
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }//傳入StrBlob和sz的建構器，那weak_ptr就會指去StrBlob的vector，跟shared_ptr共享物件
    string& deref() const; //成員函式deref
    StrBlobPtr& incr(); //前綴版本
private:
    //檢查成功的情況下check回傳shared_ptr
    shared_ptr<vector<string>>
        check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};
shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); //這個vector 存在嗎
    if (!ret)
        // ret是null才會進來
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    //因為ret是wptr.lock，所以假設存在，那ret是一個shared_ptr指向StrBlob的那個vector<string>，取size所以得知，如果那個vector的size小於0也會爆error
    return ret;
    // 都沒事(size夠大、而且還存在，就給你用)
}
StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr; 
    return *this;
}
string& StrBlobPtr::deref() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr]; //這個回傳的是給了vector[index]的那個string
    }
StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end() {return StrBlobPtr(*this, data->size());}
int main()
{
    std::ifstream ifs("data/book");
    StrBlob blob;
    for (string str; std::getline(ifs, str); )
        blob.push_back(str);
    cout<<blob.size()<<endl;
    StrBlobPtr beg = blob.begin(), end = blob.end();
    for(int i=0; i<blob.size(); ++i)
    {
        cout<<beg.deref()<<endl;
    }
    return 0;
}