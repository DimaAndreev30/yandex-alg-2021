#include <iostream>

#include <vector>

#include <cstdint>


int main()
{
	int n, d;
	std::cin >> n >> d;

	std::vector<int> distances(n);
	for (int i = 0; i < n; i++)
		std::cin >> distances[i];
	
	
	uint_fast64_t result = 0;
	for (int l = 0, r = 1; r < n; )
	{
		if (distances[r] - distances[l] > d)
		{
			result += n - r;
			l++;
		}
		else
		{
			r++;
		}
	}
	
	
	std::cout << result;
	
	return 0;
}