#include <vector>
using namespace std;
//example.h
class Example {
public:
    static double rate; //a member with an in-class initializer must be const
    static constexpr int vecSize = 20;
    //vector<double> vec(vecSize); // member "Example::vecSize" is not a type name
};