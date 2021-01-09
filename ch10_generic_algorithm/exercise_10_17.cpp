// Exercise 10.17
// Rewrite exercise 10.12 from 10.3.1 (p. 387) 
// to use a lambda in the call to sort instead of the compareIsbn function. 
//      Exercise 10.12:
//      Write a function named compareIsbn that compares the isbn() members of two Sales_data objects.
//      Use that function to sort a vector that holds Sales_data objects.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include "Sales_data.h"

bool compareIsbn(Sales_data &data1, Sales_data &data2)
{
    return data1.isbn() < data2.isbn();
}

int main(){
    vector<Sales_data> Sales_data_vector;
    // using cin constructors to read data/data_to_sort
    while (cin){
        Sales_data trans(cin);
        if (!cin) break;
        //print(cout, trans) << endl;
        Sales_data_vector.push_back(trans);
    }
    cout << "original isbn : "<<endl;
    //cout <<"size of vector : "<<Sales_data_vector.size()<<endl;
    for (auto &i : Sales_data_vector){
        print(cout, i)<<endl;
    }
    sort(Sales_data_vector.begin(), Sales_data_vector.end(), [](Sales_data &data1, Sales_data &data2){return data1.isbn()<data2.isbn();});
    cout << "after sort : "<<endl;
    //cout <<"size of vector : "<<Sales_data_vector.size()<<endl;
    for (auto &i : Sales_data_vector){
        print(cout, i)<<endl;
    }
    return 0;
}