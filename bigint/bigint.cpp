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
    {
        _value = src._value;
    }
    return *this;
}

std::string bigint::operator+(const bigint& src)
{
    std::string val1 = _value;
    std::string val2 = src._value;
    std::string result;
    size_t      j;
    int     flag;

    if (val1.size() < val2.size())
        swap(val1, val2);
    j = val2.size() - 1;
    flag = 0;
    for (size_t i = val1.size() - 1; i > 0; i--)
    {
        int a = val1[i] - '0';
        int b = val2[j] - '0';
        if (j >= 0)
            j--;
        if (flag == 1)
        {
            a++;
            flag = 1;
        }
        int c = a + b;
        if (c > 9)
        {
            c %= 10;
            flag = 1;
        }
        result.insert(0, 1, '0' + c);
    }
    return result;
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