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
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);
    std::cout<<"sum of vector :"<<"<";
    for (auto i : ivec){
        std::cout<<i<<" ";
    }
    std::cout<<"> ";
    std::cout<< "is : "<< sum << std::endl;
    return 0;
}