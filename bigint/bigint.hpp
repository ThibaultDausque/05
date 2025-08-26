#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <ostream>
# include <sstream>
# include <string>

class bigint
{
    private:
        std::string _value;
    
    public:
        bigint();
        bigint(const bigint& cpy);
        ~bigint();
        bigint(int nb);
        bigint& operator=(const bigint& src);

        std::string    getValue(void) const;

        std::string operator+(const bigint& src);
        bigint& operator+=(const bigint& src);
};

std::ostream&   operator<<(std::ostream& os, const bigint& src);

#endif