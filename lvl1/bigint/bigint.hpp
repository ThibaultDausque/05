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
		bigint(const int src);
		~bigint();

		bigint&	operator=(const bigint& src);
		bigint	operator+(const bigint& src) const;
		bigint&	operator+=(const bigint& src);
		bigint	operator++(int);
		bigint&	operator++(void);

		

		const std::string&	getValue() const;
};

std::ostream&	operator<<(std::ostream& os, const bigint& src);

#endif