//g++ exercise_3_17.cpp && ./a.out
/*
- 練習3.17: 從cin讀取一序列字詞，並將那些值儲存為一個vector。在你讀完了所有的字詞之後，就處理那個vector並將每個字詞變為大寫。印出變換後的元素，一行八個字。
 */
#include<iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main(){
	vector<string> vstring;
	string str;
    char ch;
    cout<< "enter a sequence of word, split by \" \", end with ENTER"<<endl;
	while (cin >> str)
	{
		vstring.push_back(str);
        ch = getchar();
        if (ch=='\n')
            break;
	}
    int out_cnt=0;
    for (auto sstr : vstring){
        for (auto &schar : sstr){
            schar = toupper(schar);
            cout<<schar;
            out_cnt++;
            if ((out_cnt%8)==0){
                cout<<endl;
            }
        }
        cout<<";"<<endl;
    }
    return 0;
}