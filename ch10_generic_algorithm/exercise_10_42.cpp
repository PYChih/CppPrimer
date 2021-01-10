// Exercise 10.42:
// Reimplement the program that eliminated duplicate words that
// we wrote in § 10.2.3 (10.9) to use a list instead of a vector.
//          Exercise 10.9:
//          Implement your own version of elimDups. Test your program by printing
//          the vector after you read the input, after the call to unique, and after
//          the call to erase.
//
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
using std::vector; using std::cout; using std::endl; using std::list; using std::cin; using std::fill_n; using std::string;
void print_list(const list<string> &words)
{
    for (auto i : words){
        cout<<i<<" ";
    }
    cout<<endl;
}

void elimDups(list<string> &words)
{
    words.sort();
    cout<<"after you sort :"<<endl;
    print_list(words);
    //auto end_iter = std::unique(words.begin(), words.end());
    words.unique();
    cout<<"after you unique :"<<endl;
    print_list(words);
    //words.erase(end_iter, words.end());
    //words.remove()
    //cout<<"after you erase :"<<endl;
    //print_list(words);
}

int main(){
    list<string> words{"a", "b", "c", "a", "b", "c"};
    cout<<"after you read the input :"<<endl;
    print_list(words);
    elimDups(words);

    return 0;
}