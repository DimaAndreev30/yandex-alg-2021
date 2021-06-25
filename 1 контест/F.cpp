#include <iostream>

#include <array>

#include <algorithm>


void run()
{
	int a1, b1, a2, b2;
	
	std::cin >> a1 >> b1 >> a2 >> b2;
	
	auto variants = std::array<std::pair<int, int>, 4>{
		{a1 + a2, std::max(b1, b2)},
		{a1 + b2, std::max(b1, a2)},
		{b1 + b2, std::max(a1, a2)},
		{b1 + a2, std::max(a1, b2)}};
	auto [a, b] = *std::min_element(
		variants.begin(), variants.end(),
		[](const std::pair<int, int>& x, const std::pair<int, int>& y) -> bool
			{ return x.first*x.second < y.first*y.second; });
		
	std::cout << a << ' ' << b;
}


int main()
{
	run();
	
	return 0;
}