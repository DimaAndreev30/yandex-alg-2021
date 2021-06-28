#include <iostream>

#include <vector>


void readRoute(std::vector<int> &up, std::vector<int> &down, int N)
{
	int y, prev_y, diff;
	
	std::cin >> prev_y >> prev_y;
	for (int i = 1; i < N; i++)
	{
		std::cin >> y >> y;
		diff = y - prev_y;
		
		up[i] = up[i - 1];
		down[i] = down[i - 1];
		if (diff > 0)
			up[i] += diff;
		else
			down[i] += diff;
		
		prev_y = y;
	}
}


int main()
{
	int N, M;
	
	std::cin >> N;
	std::vector<int> up(N), down(N);
	readRoute(up, down, N);
	
	std::cin >> M;
	int start, end;
	for (int i = 0; i < M; i++)
	{
		std::cin >> start >> end;
		start -= 1;
		end -= 1;
		
		if (start < end)
			std::cout << up[end] - up[start] << std::endl;
		else if (start > end)
			std::cout << down[end] - down[start] << std::endl;
		else
			std::cout << 0 << std::endl;
	}
}