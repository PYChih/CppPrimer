//  Exercise 11.31
//  Write a program that defines a multimap of authors and their works.
//  Use **find** to find **an element** in the multimap and erase that element.
//  Be sure your program works correctly if the element you look for is not in the map.
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    multimap<string, string> authors{{"Alain de Botton", "Abook"},
                                     {"Alain de Botton", "Bbook"}};
    //string search_item("Alain de Botton"); //某個作者的名子
    string search_item("nobody");
    int num_book= authors.count(search_item);
    cout<<search_item<<" write "<<num_book<<" book"<<endl;
    auto iter = authors.find(search_item);
    while(num_book>0){
        cout<<iter->second<<endl;
        --num_book;
        ++iter;
    }
    return 0;
}