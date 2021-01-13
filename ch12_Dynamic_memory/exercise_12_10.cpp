// Exercise 12.10:
// Explain whether the following call to the process function defined on page
// 464 is correct. If not, how would you correct the call?
#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;

void process(std::shared_ptr<int> ptr)
{
    cout<<"inside the process function:" << ptr.use_count() << endl;
}


int main()
{
    std::shared_ptr<int> p(new int(42));// use new to initialize the shared_ptr p
    cout<<"count after initial"<< p.use_count()<<endl;
    process(std::shared_ptr<int>(p));
    cout<<"after call function "<< p.use_count()<<endl;
}