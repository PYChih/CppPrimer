// Exercise 10.13:
// The library defines an algorithm named partition that takes a predicate
// and partitions the container so that values for which the predicate is
// true appear in the first part and those for which the predicate is false
// appear in the second part. The algorithm returns an iterator just past
// the last element for which the predicate returned true. Write a function
// that takes a string and returns a bool indicating whether the string has
// five characters or more. Use that function to partition words. Print the
// elements that have five or more characters.
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool sizebiggerthanfive(const string & s1){
    return s1.size()>=5;
}

int main(){
    vector<string> vector_string{"1", "11", "111", "1111", "11111", "111111", "1111111", "11111111"};
    auto g5_iter_end = partition(vector_string.begin(), vector_string.end(), sizebiggerthanfive);
    for (auto beg=vector_string.begin(); beg!=g5_iter_end; ++beg){
        cout<<*beg<<endl;
    }
    return 0;
}