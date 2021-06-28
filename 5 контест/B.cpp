#include <iostream>

#include <vector>


int main()
{
	int N, K;
	std::cin >> N >> K;
	
	std::vector<int> numbers(N);
	for (int i = 0; i < N; i++)
		std::cin >> numbers[i];

	
	int result = 0;
	for (int l = 0, r = 1, sum = numbers[0];; )
	{
		if (sum > K)
		{
			sum -= numbers[l];
			l += 1;
		}
		else 
		{
			if (sum == K)
				result += 1;
			
			if (r >= N)
				break;
			
			sum += numbers[r];
			r += 1;
		}
	}
	
	
	std::cout << result;
	
	return 0;
}