#include <iostream>

#include <cmath>
#include <cstdint>


int main()
{
	int w, h, n;
	std::cin >> w >> h >> n;
	
	uint_fast64_t left = std::sqrt((static_cast<double>(n)*h)*w)/(1 + 1e-6);
	uint_fast64_t right = 3 + (w + h) + left;
	while (left < right)
	{
		uint_fast64_t middle = (left + right)/2;
		uint_fast64_t k = (middle/w) * (middle/h);
		if (k < n)
			left = middle + 1;
		else
			right = middle;
	}
	
	std::cout << right;
	
	return 0;
}