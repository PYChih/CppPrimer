// Exercise 10.5:
// In the call to equal on rosters, what would happen if both rosters held C-style strings, rather than library strings?
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
int main(){
    std::vector<const char*> roster1={"Apple", "Bryan", "Chih"};
    std::list<const char*> roster2={"Apple", "Bryan", "Chih", "aaa"};
    std::cout<<std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin())<<std::endl;
    std::cout << (void*)roster1[0]<<std::endl;
    std::cout<<(void*)roster2.front()<<std::endl;
    return 0;
}