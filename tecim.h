#ifndef TECIM_H
#define TECIM_H

#include <cstring>
#include <map>
#include <math.h>
#include <iostream>

class tecim {
public:
    tecim() = default;
    explicit tecim(unsigned long long value)
        : value_(value){}
    tecim operator++(int);
    tecim& operator++();
    tecim operator--(int);
    tecim& operator--();
    int getDigitsSum();
    unsigned long long getValue();
private:
    unsigned long long value_;
public:
    friend tecim operator"" _tr (const char* val);
    friend std::ostream& operator<<(std::ostream& os, const tecim& obj);
    friend bool operator == (const tecim & rhs, const tecim & lhs);
    friend bool operator != (const tecim & rhs, const tecim & lhs);
    friend bool operator < (const tecim & rhs, const tecim & lhs);
    friend bool operator <= (const tecim & rhs, const tecim & lhs);
    friend bool operator > (const tecim & rhs, const tecim & lhs);
    friend bool operator >= (const tecim & rhs, const tecim & lhs);
};

inline std::ostream& operator<<(std::ostream& os, const tecim& obj)
{
    os << obj.value_;
    return os;
}

inline tecim operator"" _tr (const char*  val) {
    const std::map<char, int> dic{
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'A', 10},
    {'B', 11},
    {'C', 12}};
    unsigned long long result = 0;
    size_t size = strlen(val);
    for (size_t i = size - 1; i >= 2 ; --i){
        const int degree = size - i - 1;
        if (dic.find(val[i]) == dic.end())
            throw "Unsupported character";
        result += dic.at(val[i])*pow(13, degree);
    }
    return tecim(result);
}


#endif // TECIM_H
