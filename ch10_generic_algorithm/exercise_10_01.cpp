// Exercise 10.1:
// The algorithm header defines a function named count that, like find,
// takes a pair of iterators and a value.count returns a count of how
// often that value appears.
// Read a sequence of ints into a vector and print the count of how many
// elements have a given value.
//
// Exercise 10.2:
// Repeat the previous program, but read values into a list of strings.
//
#include<iostream>
#include<algorithm>
#include<iterator>
using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;
using std::count;
int main(){
    int seq_of_ints[] = {1, 2, 3, 1, 2, 3, 1, 1, 3};
    auto it_beg = begin(seq_of_ints), it_end=end(seq_of_ints);
    int return_times = count(it_beg, it_end, 1);
    cout<<"the value "<< 1 << " appears " << return_times <<" times"<<endl;

    return 0;
}