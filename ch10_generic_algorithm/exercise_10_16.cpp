// Exercise 10.16:
// Write your own version of the biggies function using lambdas.
//
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string make_plural(size_t ctr, const string &word,
                                const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}


void print_vector(const vector<string> &words)
{
    for (auto i : words){
        cout<<i<<" ";
    }
    cout<<endl;
}
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    cout<<"after you sort :"<<endl;
    print_vector(words);
    //stable_sort(words.begin(), words.end(), isShorter);
    //cout<<"after you stable sort :"<<endl;
    //print_vector(words);
    auto end_iter = std::unique(words.begin(), words.end());
    cout<<"after you unique :"<<endl;
    print_vector(words);
    words.erase(end_iter, words.end());
    cout<<"after you erase :"<<endl;
    print_vector(words);
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [sz](const string &a, const string &b)
                {return a.size() < b.size(); });
    cout<<"after you stable_sort :"<<endl;
    print_vector(words);
    auto wc = find_if(words.begin(), words.end(),
                        [sz](const string &a)
                        { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout<< count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
            [](const string &s){cout << s << " ";});
    cout << endl;
}


int main(){
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    cout<<"after you read the input :"<<endl;
    print_vector(words);
    biggies(words, 5);
    return 0;
}