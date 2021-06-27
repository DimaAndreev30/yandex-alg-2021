#include <iostream>
#include <unordered_map>
#include <algorithm>

#include <cstdint>


int main()
{
	int N;
	unsigned w, h;
	std::unordered_map<unsigned, unsigned> max_heights;
	
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> w >> h;
		max_heights[w] = std::max(max_heights[w], h);
	}	
	
	uint_fast64_t result = 0;
	for (auto [_, height] : max_heights)
		result += height;
	
	std::cout << result;
	
	
	return 0;
}