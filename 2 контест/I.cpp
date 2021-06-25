#include <iostream>

#include <vector>



int main()
{
	int N, M, K;
	std::cin >> N >> M >> K;
	
	std::vector<std::vector<int> > field(N, std::vector<int>(M, 0));
	
	int p, q;
	for (int k = 0; k < K; k++)
	{
		std::cin >> p >> q;
		p -= 1;
		q -= 1;
		
		for (int i = std::max(0, p - 1); i < std::min(N, p + 2); i++)
			for (int j = std::max(0, q - 1); j < std::min(M, q + 2); j++)
				field[i][j] += 1;
			
		field[p][q] = -9;
	}
	
	for (auto line : field)
	{
		for (auto value : line)
		{
			if (value >= 0)
			{
				std::cout << value << ' ';
			}
			else
			{
				std::cout << '*' << ' ';
			}
		}
		
		std::cout << '\n';
	}
	
	return 0;
}