// Exercise 11.7:
// Define a map for which the key is the family’s last name and
// the value is a vector of the children’s names. Write code to
// add new families and to add new children to an existing family.

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

int main(){
    map<string, vector<string>> family{
        {"Griffiths", {"David", "Dawn"}},
        {"Joe", {"Gibson", "Gibson Jr."}}
        };
    family["new last name"] = {"new child name", "new child name 2"};
    family["Joe"].push_back("Goro Shigeno");

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