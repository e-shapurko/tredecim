#include <iostream>
#include <map>
#include "tecim.h"

using namespace std;

int main()
{
    std::map<int, int> sums;
    unsigned long long count = 0;
    for (auto i = 0x0_tr; i <= 0xCCCCCC_tr; i++){
        sums[i.getDigitsSum()] += 1;
    }
    for (auto it = sums.begin(); it != sums.end(); ++it){
        count += pow((*it).second, 2);
        std::cout << "sum:" << (*it).first << " count: " << (*it).second << std::endl;
    }
    std::cout << "count: " << count << std::endl;
    std::cout << "count: " << count * 13 << std::endl;

    return 0;
}

