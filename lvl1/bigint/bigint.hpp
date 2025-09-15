#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <sstream>

class bigint
{
	private:
		std::string		_value;

	public:
		bigint();
		bigint(const bigint &cpy);
		bigint(const std::string& src);
		~bigint();

		bigint&	operator=(const bigint& src);
		bigint&	operator+(const bigint& src);
};

std::ostream&	operator<<(std::ostream& os, const bigint& src);

#endif