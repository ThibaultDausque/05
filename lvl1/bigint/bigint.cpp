#include "bigint.hpp"

bigint::bigint()
{
	this->_value = "0";
}

bigint::bigint(const bigint& src)
{
	*this = src;
}

bigint::bigint(const std::string& src)
{
	std::ostringstream	oss;

	oss << src;
	this->_value = oss.str();
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

bigint&	bigint::operator+(const bigint& src)
{
	std::string	val1 = this->_value;
	std::string	val2 = src._value;
	std::string	result;

	if (val1.size() < val2.size())
		std::swap(val1, val2);
	int		size = val1.size();
	int		j = val2.size() - 1;

	for (int i = size - 1; i >= 0; i--)
	{
		int		a = val1[i];
		int		b = val2[j];

		if (j >= 0)
			j--;
		int c = a + b;
		if (c > 9)
		{
			c %= 10;
			result.insert(0, 1, c + '0');
			
		}
	}
}