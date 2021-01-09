// Exercise 10.31:
//   Update the program from the previous exercise so that it prints only the unique elements.
//  Your program should use unqiue_copy

#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> ivec;
    cout<<"input a vector<int> ctrl+d to end"<<endl;
    istream_iterator<int> in(cin), end;
    // read and istream_iterator
    while(in!=end){
        ivec.push_back(*in++);
    }
    // copy and ostream_iter
    cout<< "input vector:"<<endl;
    copy(ivec.begin(), ivec.end(), out_iter);
    cout<<endl;
    // sort
    sort(ivec.begin(), ivec.end());
    // copy and ostream_iterator
    cout<< "sorted vector:"<<endl;
    unique_copy(ivec.begin(), ivec.end(), out_iter);
    cout<<endl;

    return 0;
}