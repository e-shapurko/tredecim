#include "tecim.h"

tecim tecim::operator++(int)
{
    tecim oldValue(*this);
    this->value_ ++;
    return oldValue;
}

tecim &tecim::operator++()
{
    this->value_ ++;
    return *this;
}

tecim tecim::operator--(int)
{
    tecim oldValue(*this);
    this->value_ --;
    return oldValue;
}

tecim &tecim::operator--()
{
    this->value_ --;
    return *this;
}

int tecim::getDigitsSum()
{
    unsigned long long dig = value_;
    int sum = 0;
    while (true) {
        if (dig <= 12) {
            sum += dig;
            return sum;
        } else {
            auto cell = dig % 13;
            sum += cell;
            dig = dig / 13;
        }
    }
}

unsigned long long tecim::getValue()
{
    return value_;
}

bool operator >=(const tecim &rhs, const tecim &lhs)
{
    return rhs.value_ >= lhs.value_;
}

bool operator <=(const tecim &rhs, const tecim &lhs)
{
    return rhs.value_ <= lhs.value_;
}

bool operator >(const tecim &rhs, const tecim &lhs)
{
    return rhs.value_ > lhs.value_;
}

bool operator < (const tecim &rhs, const tecim &lhs)
{
    return rhs.value_ < lhs.value_;
}

bool operator !=(const tecim &rhs, const tecim &lhs)
{
    return rhs.value_ != lhs.value_;
}

bool operator ==(const tecim &rhs, const tecim &lhs)
{
    return rhs.value_ == lhs.value_;
}

