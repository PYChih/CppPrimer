// Exercise 10.3:
// Use accumulate to sum the elements in a vector<int>.
//
// Exercise 10.4:
// Assuming v is a vector<double>, what, if anything,
// is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?
//  Check below.
//

#include<iostream>
#include<vector>
#include<numeric>

int main(){
    std::vector<double> v{1.1, 2.1, 3.1};
    auto sum = std::accumulate(v.cbegin(), v.cend(), 0);
    std::cout<<"wrong answer : "<<sum<<std::endl;
    auto dsum = std::accumulate(v.cbegin(), v.cend(), 0.);
    std::cout<<"true answer : "<<dsum<<std::endl;

    return 0;
}