#include "bigint.hpp"

bigint::bigint()
{
    _value = "null";
}

bigint::bigint(const bigint &cpy)
{
    *this = cpy;
}

bigint::bigint(const int nb)
{
    std::ostringstream  oss;

    oss << nb;
    _value = oss.str();
}

bigint::~bigint()
{

}

bigint& bigint::operator=(const bigint &src)
{
    if (this != &src)
        this->_value = src._value;
    return *this;
}

bigint bigint::operator+(const bigint& src)
{
    std::string value1 = _value;
    std::string value2 = src._value;
    std::string result;
    bigint  copy(*this);
    int     flag = 0;

    if (value1.size() < value2.size())
        swap(value1, value2);
    int j = value2.size() - 1;
    for (int i = value1.size() - 1; i >= 0; i--)
    {
        int a = value1[i] - '0';
        int b = value2[j] - '0';
        int c;
        int d;
        char nb;
        if (flag == 1)
        {
            c = a + b + 1;
            flag = 0;
        }
        else
            c = a + b;
        if (c >= 10)
        {
            flag = 1;
            d = c % 10;
        }
        if (j != 0)
            j--;
        if (flag == 0)
            nb = '0' + c;
        else
            nb = '0' + d;
        result.insert(0, 1, nb);
    }
    copy._value = result;
    return copy;
}

std::ostream&   operator<<(std::ostream& os, const bigint& src)
{
    os << src.getValue();
    return os;
}

const std::string&    bigint::getValue(void) const
{
    return _value;
}