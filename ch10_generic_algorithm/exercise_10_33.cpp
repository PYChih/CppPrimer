// Exercise 10.33:
//   Write a program that takes the names of an input file and two output files.
//  The input file should hold integers. Using an istream_iterator read the input file.
//  Using ostream_iterators, write the odd numbers into the first output file.
//  Each value should be followed by a space.Write the even numbers into the second file.
//  Each of these values should be placed on a separate line.

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
    ifstream in("data/some_number");
    ofstream odd_out("data/odd", ofstream::app), eve_out("data/eve", ofstream::app);
    ostream_iterator<int> odd_it(odd_out, " "), eve_it(eve_out, "\n");
    int i;
    while(in>>i)
        //cout<<i<<endl;
        if (i%2){
            odd_it = i;
        } else{
            eve_it = i;
        }

    return 0;
}