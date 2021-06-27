#include <iostream>
#include <vector>


int main()
{
	int N, k;
	
	std::cin >> N;
	std::vector<int> counts(N);
	
	int count;
	for (int i = 0; i < N; i++)
	{
		std::cin >> count;
		counts[i] = count;
	}
	
	
	std::cin >> k;
	int button;
	for(int i = 0; i < k; i++)
	{
		std::cin >> button;
		counts[button - 1] -= 1;
	}
	
	
	for (int i = 0; i < N; i++)
	{
		if (counts[i] >= 0)
			std::cout << "NO\n";
		else
			std::cout << "YES\n";
	}
	
	return 0;
}
