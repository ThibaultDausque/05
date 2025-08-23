#include "vect2.hpp"

int	main(void)
{
	vect2		v1;
	vect2		v2(1, 2);
	const vect2	v3(v2);
	vect2		v4 = v2;

	std::cout << v2 << std::endl;
	std::cout << "{ " << v2.getValue(0) << ", " << v2.getValue(1) << " }" << std::endl;
	
	std::cout << "v4++ = " << v4++ << std::endl;// 2, 3
	std::cout << "++v4 = " << ++v4 << std::endl;// 3, 4
	// std::cout << "v4-- = " << v4-- << std::endl;// 2, 3
	// std::cout << "v4-- = " << --v4 << std::endl;// 1, 2
}