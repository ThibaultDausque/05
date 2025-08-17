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
        int c = 0;
        int d;
        char nb;
        
        if (j > -1)
            c = a + b;
        else
            c = a;
        if (flag == 1)
        {
            c++;
            flag = 0;
        }
        if (c >= 10)
        {
            flag = 1;
            d = c % 10;
            nb = '0' + d;
            result.insert(0, 1, nb);
            if (i == 0)
                result.insert(0, 1, '1');
        }
        else
        {
            nb = '0' + c;
            result.insert(0, 1, nb);
        }
        j--;
    }
    copy._value = result;
    return copy;
}

bigint& bigint::operator+=(const bigint& src)
{
    *this = *this + src;
    return *this;
}

bigint bigint::operator++(void)
{
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint  tmp = *this;

    *this += bigint(1);
    return tmp;
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