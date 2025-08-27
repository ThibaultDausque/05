#include "bigint.hpp"

bigint::bigint()
{
    _value = "0";
}

bigint::bigint(const bigint& src)
{
    *this = src;
}

bigint::~bigint()
{

}

bigint::bigint(int nb)
{
    std::ostringstream oss;
    oss << nb;
    _value = oss.str();
}

bigint& bigint::operator=(const bigint& src)
{
    if (this != &src)
        this->_value = src._value;
    return *this;
}

bigint bigint::operator+(const bigint& src) const
{
    std::string val1 = _value;
    std::string val2 = src._value;
    std::string result;
    int     j;
    int     flag;

    if (val1.size() < val2.size())
        swap(val1, val2);
    j = val2.size() - 1;
    flag = 0;
    for (int i = val1.size() - 1; i >= 0; i--)
    {
        int a = val1[i] - '0';
        int b = val2[j] - '0';

        if (flag == 1)
        {
            a++;
            flag = 1;
        }
        int c = 0;
        if (j >= 0)
            c = a + b;
        else
            c += a;
        if (c > 9)
        {
            c %= 10;
            flag = 1;
        }
        result.insert(0, 1, '0' + c);
        j--;
    }
    bigint  cpy(*this);
    cpy._value = result;
    return cpy;
}

bigint bigint::operator+=(const bigint& src)
{
    *this = *this + src;
    return *this;
}

bigint&  bigint::operator++(void)
{
    bigint one(1);
    *this += one;
    return *this;
}

bigint  bigint::operator++(int)
{
    bigint  cpy(*this);
    bigint  one(1);
    *this += one;
    return cpy;
}

std::string    bigint::getValue(void) const
{
    return _value;
}

std::ostream&   operator<<(std::ostream& os, const bigint& src)
{
    os << src.getValue();
    return os;
}