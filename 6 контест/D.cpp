#include <iostream>

#include <cmath>
#include <cstdint>


uint_fast64_t findMax(
		uint_fast64_t n, uint_fast64_t a, uint_fast64_t b,
		uint_fast64_t w, uint_fast64_t h)
{
	uint_fast64_t left = 1;
	uint_fast64_t right = std::max(w - a, h - b)/2 + 1;
	while (left < right)
	{
		uint_fast64_t middle = (left + right)/2;
		uint_fast64_t k = (w/(a + 2*middle)) * (h/(b + 2*middle));
		
		if (k >= n)
			left = middle + 1;
		else
			right = middle;
	}
	
	return left - 1;
}


int main()
{
	uint_fast64_t n, a, b, w, h;
	std::cin >> n >> a >> b >> w >> h;
	
	std::cout << std::max(findMax(n, a, b, w, h), findMax(n, a, b, h, w));
	
	return 0;
}