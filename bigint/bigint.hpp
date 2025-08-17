#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <string>
# include <sstream>

class bigint
{
    private:
        std::string _value;
    
    public:
        bigint();
        bigint(const bigint &cpy);
        bigint& operator=(const bigint &src);
        bigint(const int nb);
        ~bigint();

        const std::string&   getValue(void) const;

        bigint operator+(const bigint& src);
        bigint& operator+=(const bigint& src);
        bigint operator++(void);
        bigint operator++(int);

};

std::ostream&    operator<<(std::ostream& os, const bigint& src);

#endif