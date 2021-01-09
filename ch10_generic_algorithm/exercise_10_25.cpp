// Exercise 10.25:
// In the exercises for 10.3.2(Exercise 10.18 and 10.19) you wrote a version of biggies that uses partition.
//          Rewrite that function to use check_size and bind.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
using std::placeholders::_1;

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
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [sz](const string &a, const string &b)
                {return a.size() < b.size(); });
    cout<<"after you stable_sort :"<<endl;
    print_vector(words);
    //auto wc = find_if(words.begin(), words.end(),
    //                    [sz](const string &a)
    //                    { return a.size() >= sz; });
    //auto wc = stable_partition(words.begin(), words.end(),
    //                    [sz](const string &a){ return a.size() >=sz;});
    auto wc = stable_partition(words.begin(), words.end(),
                        bind(check_size, _1, sz));
    auto count = wc - (words.begin());
    cout<< count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), wc,
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