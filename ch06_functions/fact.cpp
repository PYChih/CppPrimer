#include "Chapter6.h"

int fact(int val)
{
    int ret = 1;
    while (val>1)
        ret *= val--;
    return ret;

}

double abs(double val)
{
    if (val <0){
        val = -val;
    }
    return val;
}
