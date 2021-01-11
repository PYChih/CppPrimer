// Exercise 11.18:
// Write the type of map_it from the loop on page 430 without using auto or decltype.
//
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::pair;

int main(){
    map<string, size_t> word_count;
    map<string, size_t>::const_iterator map_it = word_count.cbegin();
    return 0;
}