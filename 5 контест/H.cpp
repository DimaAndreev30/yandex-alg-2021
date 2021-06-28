#include <iostream>

#include <string>
#include <array>

#include <cstdint>


int main()
{
	int n, k;
	std::string word;
	std::array<int, 26> counter{};
	
	std::cin >> n >> k >> word;
	
	
	int maxRange = 0, pos = 0;
	int left, right;
	for (left = 0, right = 0; right < n; right++)
	{
		uint_fast8_t indx = word[right] - 'a';
		counter[indx] += 1;
		
		if (counter[indx] > k)
		{
			if (right - left > maxRange)
			{
				maxRange = right - left;
				pos = left;
			}
			
			uint_fast8_t left_indx;
			do
			{
				left_indx = word[left] - 'a';
				counter[left_indx] -= 1;
				left += 1;
			} while (left_indx != indx);
		}
	}
	if (n - left > maxRange)
	{
		maxRange = n - left;
		pos = left;
	}
	
	
	std::cout << maxRange << ' ' << pos + 1;
	
	return 0;
}