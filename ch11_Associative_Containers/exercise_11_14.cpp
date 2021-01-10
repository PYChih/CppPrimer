// Exercise 11.14:
// Extend the map of children to their family name that you wrote for the
// exercises in § 11.2.1 (p. 424) by having the vector store a pair that
// holds a child’s name and birthday.
//
//      Exercise 11.7:
//      Define a map for which the key is the family’s last name and
//      the value is a vector of the children’s names. Write code to
//      add new families and to add new children to an existing family.
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
    map<string, vector< pair<string, string> > > family{
        {"Griffiths", {{"David", "19920101"}, {"Dawn", "19920101"} }},
        {"Joe", { {"Gibson", "19930303"}, {"Gibson Jr.", "19940709"}}}
        };
    family["new last name"] = { {"new child name", "20200101"}, {"new child name 2", "20200102"}};
    family["Joe"].push_back({"Goro Shigeno", "19830808"});

    //print a map
    for (auto const& lastname : family)
    {
        cout<<"family: ";
        cout<< lastname.first<<endl;
        for (auto const& child_name : lastname.second){
            cout<<child_name.first<<" birthday:"<<child_name.second<<endl;
        }
    }
    return 0;
}