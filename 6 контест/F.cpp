#include <iostream>

#include <algorithm>
#include <cstdint>


int main()
{
	unsigned N;
	unsigned x, y;
	std::cin >> N >> x >> y;
	
	unsigned m = (N*y + x - 1)/(x + y);
	std::cout << std::min(x, y) + std::min(m*x, (N - m)*y);
	
	return 0;
}