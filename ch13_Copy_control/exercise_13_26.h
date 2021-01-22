#ifndef CH13_COPY_CONTROL_EXERCISE_13_26_H_
#define CH13_COPY_CONTROL_EXERCISE_13_26_H_
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
class StrBlob {
 public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);  // NOLINT: this is exercise 12_05
    size_type size() const { return data->size();}
    // create copy constructure
    // value like version
    StrBlob(const StrBlob& vs): data(make_shared<vector<string>>(*vs.data)) { }
    // create copy assign operator
    // value like version
    StrBlob& operator=(const StrBlob& vs) {
        shared_ptr<vector<string>> temp = make_shared<vector<string>>(*vs.data);
        data.reset();
        data = temp;
        return *this;
    }
    bool empty() const { return data->empty();}
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();
    shared_ptr<vector<string>> get_data() { return data; }
    int get_count() { return data.use_count(); }
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;

 private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):
                data(make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}
string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data-> pop_back();
}
const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}
const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}
#endif  // CH13_COPY_CONTROL_EXERCISE_13_26_H_
