#include <iostream>

#include <cmath>
#include <cstdint>


int main()
{
	uint_fast64_t n, m, t;
	std::cin >> n >> m >> t;
	
	uint_fast64_t D = (m + n)*(m + n) - 4*t;
	uint_fast64_t sqrtD = std::sqrt(D);
	if (sqrtD*sqrtD != D) 
		sqrtD += 1;
	
	std::cout << (m + n - sqrtD)/4;
}