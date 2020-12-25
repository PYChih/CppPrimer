// g++ exercise_3_42.cpp && ./a.out
/*
 */
#include<iostream>
#include <string>
#include <vector>
#include <iterator>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
// initial and define:
/*
    int arr[10][20][30];
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    //
    int iaeq[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int ia[3][4] = {{0}, {4}, {8}};
    //
    ia[2][3] = arr[0][0][0];;
    int (&row)[4] = ia[1];
 */
/*
    // nested "for" for multidimarray
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];
    for (size_t i=0; i!=rowCnt; ++i){
        for (size_t j =0; j!=colCnt; ++j){
            ia[i][j] = i * colCnt + j;
        }
    }
 */
/*
    // range for:
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];
    size_t cnt=0;
    for (auto &row : ia){
        for (auto &col : row){
            col = cnt;
            ++cnt;
        }
    }
 */
/*
    int ia[3][4];
    int (*p)[4] = ia;
    p = &ia[2];
    //int *ip[4]
    //int (*ip)[4]
    for (auto p = ia; p!= ia+3; ++p){
        for (auto q = *p; q!=*p+4; ++q){
            cout << *q << ' ';
        }
        cout<< endl;
    }
 */
    int ia[3][4];
    for (auto p = std::begin(ia); p !=std::end(ia); ++p){
        for (auto q = std::begin(*p); q!=std::end(*p); ++q){
            cout << *q << ' ';
        }
    }
    cout<< endl;
    return 0;
}