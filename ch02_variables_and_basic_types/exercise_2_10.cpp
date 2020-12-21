/*
 * 練習2.10: 下列每個變數各有什麼初始值呢(如果有的話)?
 *std::string global_str;
 *int global_int;
 *int main()
 *{
 *    int local_int;
 *    std:string local_str;
 *}
 */
/*
 * g++ exercise_2_10.cpp && ./a.out
 */
#include <iostream>
#include <string>

std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
    std::cout << "global_str: " << global_str << std::endl;
	std::cout << "global_int: " << global_int << std::endl;
	std::cout << "local_int: " << local_int << std::endl;
	std::cout << "local_str: " << local_str << std::endl;
    
	return 0;
}