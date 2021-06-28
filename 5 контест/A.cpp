#include <iostream>

#include <vector>


int main()
{
	int N, M;
	
	std::cin >> N;
	std::vector<int> shirts(N);
	for (int i = 0; i < N; i++)
		std::cin >> shirts[i];
	
	std::cin >> M;
	std::vector<int> pants(M);
	for (int i = 0; i < M; i++)
		std::cin >> pants[i];


	int shirt_color = 0, pant_color = 0;
	int min_difference = 10000000;
	for (int s = 0, p = 0; s < N and p < M;)
	{
		int difference = shirts[s] - pants[p];
		
		if (difference < 0)
		{
			difference = -difference;
			if (difference < min_difference)
			{
				min_difference = difference;
				shirt_color = shirts[s];
				pant_color = pants[p];
			}
			
			s++;
		}
		else if (difference > 0)
		{
			if (difference < min_difference)
			{
				min_difference = difference;
				shirt_color = shirts[s];
				pant_color = pants[p];
			}
			
			p++;
		}
		else
		{
			min_difference = 0;
			shirt_color = shirts[s];
			pant_color = pants[p];
			
			break;
		}
	}
	
	std::cout << shirt_color << ' ' << pant_color;
	
	return 0;
}