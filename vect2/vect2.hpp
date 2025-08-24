#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>
# include <vector>
# include <ostream>

class vect2
{
	private:
		std::vector<int>	_vec;

	public:
		vect2();
		vect2(const vect2& cpy);
		vect2(int a, int b);
		~vect2();
		int	getValue(int i) const;
		vect2&	operator=(const vect2& src);
	
		vect2&	operator++(void);
		vect2	operator++(int);
		vect2&	operator--(void);
		vect2	operator--(int);

		vect2	operator+(const vect2& addon) const;
		vect2&	operator+=(const vect2& add);
		vect2&	operator-=(const vect2& less);
		vect2	operator*(int nb);

		bool	operator==(const vect2& src);
		bool	operator!=(const vect2& src);
};

vect2	operator*(int nb, const vect2& src);
std::ostream&	operator<<(std::ostream& os, const vect2& src);

#endif