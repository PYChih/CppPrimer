// Exercise 11.23:
// Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exercises
//  in 11.2.1 (11.7) to use a multimap.
//          Exercise 11.7:
//          Define a map for which the key is the family’s last name and
//          the value is a vector of the children’s names. Write code to
//          add new families and to add new children to an existing family.

// no operator "[]" matches these operands -- operand types are: std::multimap<std::string, std::vector<std::string, std::allocator<std::string>>, std::less<std::string>, std::allocator<std::pair<const std::string, std::vector<std::string, std::allocator<std::string>>>>> [ const char [14] ]


#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::multimap;

int main(){
    multimap<string, vector<string>> family{
        {"Griffiths", {"David", "Dawn"}},
        {"Joe", {"Gibson", "Gibson Jr."}}
        };
    family.insert({"new last name", {"new child name", "new child name 2"}});
    family.insert({"Joe", {"Goro Shigeno"}});
    //family["new last name"] = {"new child name", "new child name 2"};
    //family["Joe"].push_back("Goro Shigeno");

    //print a map
    for (auto const& lastname : family)
    {
        cout<<"family: ";
        cout<< lastname.first<<endl;
        for (auto const& child_name : lastname.second){
            cout<<child_name<<endl;
        }
    }
    return 0;
}