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
#include<string>
#include<list>

int main(){
    std::list<std::string> list_string{"aaa", "bbb", "ccc"};
    int return_times = std::count(list_string.begin(), list_string.end(), "aaa");
    std::cout<<"the value "<< "aaa" << " appears " << return_times <<" times"<<std::endl;
    return 0;
}