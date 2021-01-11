//  Exercise 11.32
//  Using the multimap from the previous exercise, 
//  write a program to print the list of **authors and their works** alphabetically.

//      Exercise 11.31
//      Write a program that defines a multimap of authors and their works.
//      Use **find** to find **an element** in the multimap and erase that element.
//      Be sure your program works correctly if the element you look for is not in the map.

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    multimap<string, string> authors{
        { "alan", "DMA" },
        { "pezy", "LeetCode" },
        { "alan", "CLRS" },
        { "wang", "FTP" },
        { "pezy", "CP5" },
        { "wang", "CPP-Concurrency" }
    };
    //string search_item("Alain de Botton"); //某個作者的名子
    //string search_item("nobody");
    //int num_book= authors.count(search_item);
    //cout<<search_item<<" write "<<num_book<<" book"<<endl;
    //auto iter = authors.find(search_item);

    auto beg = authors.begin();
    for (auto beg = authors.begin(); beg!=authors.end(); ++beg){
        string search_item = beg->first;
        cout<<beg->first<<":"<<beg->second<<endl;
    }
    while(beg!=authors.end()){
        auto num_books = authors.count(beg->first);
        cout << beg->first << " write " << num_books << (num_books>1?" books":" book")<<endl;
        vector<string> book_name;
        while(num_books>0){
            book_name.push_back(beg->second);
            ++beg;
            --num_books;
        }
        sort(book_name.begin(), book_name.end());
        for (auto i : book_name){
            cout<<i<<endl;
        }
    }

    //while(num_book>0){
    //    cout<<iter->second<<endl;
    //    --num_book;
    //    ++iter;
    //}
    return 0;
}