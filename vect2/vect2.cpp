# include "vect2.hpp"

vect2::vect2()
{
	_vec.push_back(0);
	_vec.push_back(0);
}

vect2::vect2(const vect2& cpy)
{
	*this = cpy;
}

vect2::vect2(int a, int b)
{
	_vec.push_back(a);
	_vec.push_back(b);
}

vect2::~vect2()
{

}

vect2&	vect2::operator=(const vect2& src)
{
	if (this != &src)
		_vec = src._vec;
	return *this;
}

int	vect2::getValue(int i) const
{
	return _vec[i];
}

vect2&	vect2::operator+(int add)
{
	_vec[0] = _vec[0] + add;
	_vec[1] = _vec[1] + add;
	return *this;
}

vect2&	vect2::operator++(void)
{
	_vec[0] += 1;
	_vec[1] += 1;
	return *this;
}

vect2	vect2::operator++(int)
{
	vect2	cpy;

	cpy = *this;
	_vec[0] += 1;
	_vec[1] += 1;
	return cpy;
}

std::ostream&	operator<<(std::ostream& os, const vect2& src)
{
	os << "{ " << src.getValue(0) << ", " << src.getValue(1) << " }";
	return os;
}