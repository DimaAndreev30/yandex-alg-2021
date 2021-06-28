#include <iostream>

#include <vector>

#include <cstdint>


uint_fast64_t findMax(
		unsigned N, unsigned K, 
		const std::vector<unsigned>& arrL, uint_fast64_t L)
{
	uint_fast64_t left = L/(N + K) + 1, right = L/K + 1;
	while (left < right)
	{
		uint_fast64_t middle = (left + right)/2;
		
		unsigned M = 0;
		for (int i = 0; i < N; i++)
			M += arrL[i]/middle;
	
		if (M >= K)
			left = middle + 1;
		else
			right = middle;
	}
	
	return left - 1;
}


int main()
{
	unsigned N, K;
	std::cin >> N >> K;
	
	uint_fast64_t L = 0;
	std::vector<unsigned> arrL(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> arrL[i];
		L += arrL[i];
	}
	
	
	std::cout << findMax(N, K, arrL, L);
	
	return 0;
}