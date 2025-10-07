#include "bigint.hpp"

bigint::bigint()
{
	this->_value = "0";
}

bigint::bigint(const bigint& src)
{
	*this = src;
}

bigint::bigint(const int src)
{
	std::ostringstream	oss;

	oss << src;
	this->_value = oss.str();
}

bigint::bigint(const std::string& src)
{
	this->_value = src;
}

bigint::~bigint()
{

}

bigint&	bigint::operator=(const bigint& src)
{
	if (this != &src)
		this->_value = src._value;
	return *this;
}

bigint	bigint::operator+(const bigint& src) const
{
	std::string	val1 = this->_value;
	std::string	val2 = src._value;
	std::string	result;
	int			flag = 0;

	if (val1.size() < val2.size())
		std::swap(val1, val2);
	int		size = val1.size();
	int		j = val2.size() - 1;

	for (int i = size - 1; i >= 0; i--)
	{
		int		a = val1[i] - '0';
		int		b = val2[j] - '0';
		int		c = 0;

		if (flag == 1)
		{
			a++;
			flag = 0;
		}
		if (j < 0)
			c = a;
		else
			c = a + b;
		if (c > 9)
		{
			c %= 10;
			flag = 1;
		}
		if (j >= 0)
			j--;
		result.insert(0, 1, c + '0');
	}
	bigint	cpy(result);
	return cpy;
}

bigint&	bigint::operator+=(const bigint& src)
{
	*this = *this + src;
	return *this;
}

const std::string&	bigint::getValue() const
{
	return this->_value;
}

bigint&	bigint::operator++(void)
{
	*this += 1;
	return *this;
}

bigint	bigint::operator++(int)
{
	bigint	cpy(*this);

	*this += 1;
	return cpy;
}

std::ostream&	operator<<(std::ostream& os, const bigint& src)
{
	os << src.getValue();
	return os;
}