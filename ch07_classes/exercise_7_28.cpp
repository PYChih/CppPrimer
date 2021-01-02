/*
- 練習7.28: 如果前面練習中的move、set與display的回傳型別為Screen而非Screen&，會發生什麼事?
``//最後一個display會回到一開始創建的樣子``
```
Screen myScreen(5, 5, 'X');
myScreen.move(4, 0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```
 */


#include <iostream>
#include <string>
using namespace std;
class Screen{
    public:
        //typedef and using
        typedef string::size_type pos;
        // constructor
        Screen()=default;
        Screen(pos ht, pos wd) : width(wd), height(ht), contents(wd*ht, ' ') {}
        Screen(pos ht, pos wd, char c) : width(wd), height(ht), contents(ht*wd, c) {}
        // member function
        char get() const
            { return contents[cursor];}
        inline char get(pos ht, pos wd) const;
        Screen set(char);
        Screen set(pos, pos, char);
        
        Screen move(pos r, pos c);
        Screen display(ostream &os)
                        { do_display(os); return *this;}
        const Screen display(ostream &os) const
                        { do_display(os); return *this;}
    private:
        pos cursor = 0; // 游標
        pos height = 0, width = 0;
    private:
        string contents;
        void do_display(ostream &os) const 
        {
            //os<<std::endl;
            for(int j=0; j<height; ++j){
                for (int i=0; i<width; ++i){
                    os<<contents[j*width+i];
                }
                os<<std::endl;
            }
        }
};
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}
inline Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
inline Screen Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}
inline Screen Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
int main()
{
    Screen myScreen(5, 5, 'x');
    cout<<"display(5,5,'x')"<<endl;
    myScreen.display(cout);
    cout<<"display move(4,0) and set #"<<endl;
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    cout<<"final display"<<endl;
    myScreen.display(cout);
    cout << "\n";
    return 0;
}