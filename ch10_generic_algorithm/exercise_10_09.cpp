// Exercise 10.9:
// Implement your own version of elimDups. Test your program by printing
// the vector after you read the input, after the call to unique, and after
// the call to erase.
//
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
using std::vector; using std::cout; using std::endl; using std::list; using std::cin; using std::fill_n; using std::string;
void print_vector(const vector<string> &words)
{
    for (auto i : words){
        cout<<i<<" ";
    }
    cout<<endl;
}
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    cout<<"after you sort :"<<endl;
    print_vector(words);
    auto end_iter = std::unique(words.begin(), words.end());
    cout<<"after you unique :"<<endl;
    print_vector(words);
    words.erase(end_iter, words.end());
    cout<<"after you erase :"<<endl;
    print_vector(words);
}

int main(){
    vector<string> words{"a", "b", "c", "a", "b", "c"};
    cout<<"after you read the input :"<<endl;
    print_vector(words);
    elimDups(words);

    return 0;
}