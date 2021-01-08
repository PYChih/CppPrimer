// Exercise 10.11:
// Write a program that uses stable_sort and isShorter to sort a vector passed
// to your version of elimDups.
// Print the vector to verify that your program is correct.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
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
    stable_sort(words.begin(), words.end(), isShorter);
    cout<<"after you stable sort :"<<endl;
    print_vector(words);
    auto end_iter = std::unique(words.begin(), words.end());
    cout<<"after you unique :"<<endl;
    print_vector(words);
    words.erase(end_iter, words.end());
    cout<<"after you erase :"<<endl;
    print_vector(words);
}

int main(){
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    cout<<"after you read the input :"<<endl;
    print_vector(words);
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);
    cout<<"after you stable_sort :"<<endl;
    print_vector(words);

    return 0;
}