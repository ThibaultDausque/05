#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <sstream>
# include <iostream>
# include <string>

class bigint
{
	private:
		std::string	_value;
	
	public:
		bigint();
		bigint(const bigint& cpy);
		bigint(int nb);
		~bigint();
		bigint&	operator=(const bigint& src);
		std::string	getValue() const;

		bigint	operator+(const bigint& src) const;
		bigint	operator+=(const bigint& src);
		bigint	operator++(int);
		bigint&	operator++(void);
};

std::ostream&	operator<<(std::ostream& os, const bigint& src);

#endif