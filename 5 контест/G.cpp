#include <iostream>

#include <map>

#include <cmath>
#include <algorithm>

#include <cstdint>


int main()
{
	int n;
	uint_fast64_t k;
	std::map<int, int> cardsCounter;
	
	std::cin >> n >> k;
	
	int card;
	for (int i = 0; i < n; i++)
	{
		std::cin >> card;
		cardsCounter[card] += 1;
	}
	
	
	uint_fast64_t result = 0;
	int numCards = 0, numDub = 0;
	for (auto left = cardsCounter.begin(), right = cardsCounter.begin(); 
		 right != cardsCounter.end(); right++)
	{
		while (k*left->first < right->first)
		{
			numCards -= 1;
			if (left->second > 1)
				numDub -= 1;
			
			left++;
		}
		
		result += 3*(static_cast<uint_fast64_t>(numCards)*(numCards - 1) + numDub);
		if (right->second > 1)
		{
			result += 3*numCards;
			if (right->second > 2)
				result += 1;
			
			numDub += 1;
		}
		numCards += 1;
	}
	
	
	std::cout << result;
	
	return 0;
}