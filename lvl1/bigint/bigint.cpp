#include "bigint.hpp"

bigint::bigint()
{
	_value = "0";
}

bigint::bigint(const bigint& cpy)
{
	*this = cpy;
}

bigint::~bigint()
{

}

bigint&	bigint::operator=(const bigint&	src)
{
	if (this != &src)
		this->_value = src._value;
	return *this;
}

bigint::bigint(int nb)
{
	std::ostringstream	os;

	os << nb;
	_value = os.str();
}

std::string	bigint::getValue() const
{
	return _value;
}

bigint	bigint::operator+(const bigint& src) const
{
	std::string	val1 = this->_value;
	std::string	val2 = src._value;
	std::string	result;
	bigint	cpy(*this);
	int		j;
	int		flag = 0;

	if (val1.size() < val2.size())
		std::swap(val1, val2);

	j = val2.size() - 1;
	for (int i = val1.size() - 1; i >= 0; i--)
	{
		int		a = val1[i] - '0';
		int		b = val2[j] - '0';
		int		c = 0;

		c = a + b;
		if (flag == 1)
		{
			c++;
			flag = 0;
		}
		if (c >= 10)
		{
			c %= 10;
			flag = 1;
		}
		result.insert(0, 1, c + '0');
		if (j > 0)
			j--;
	}
	cpy._value = result;
	return cpy;
}

bigint	bigint::operator+=(const bigint& src)
{
	*this = *this + src;
	return *this;
}

bigint	bigint::operator++(int)
{
	bigint	cpy(*this);

	cpy += 1;
	return cpy;
}

bigint&	bigint::operator++(void)
{
	*this += 1;
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const bigint& src)
{
	os << src.getValue();
	return os;
}

