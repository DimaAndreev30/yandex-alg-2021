#include <iostream>

#include <vector>
#include <algorithm>


bool checkPossible(const std::vector<int>& disadvantages, int C, int skips, int value)
{
	for (int i = 0; i < disadvantages.size(); )
	{
		if (disadvantages[i] > value)
		{
			if (skips <= 0)
				return false;
			skips--;
			i++;
		}
		else
		{
			i += C;
		}
	}
	
	return true;
}


int main()
{
	int N, R, C;
	std::cin >> N >> R >> C;
	
	std::vector<int> heights(N);
	for (int i = 0; i < N; i++)
		std::cin >> heights[i];
	
	std::sort(heights.begin(), heights.end());
	
	std::vector<int> disadvantages(N - C + 1);
	for (int i = 0; i < disadvantages.size(); i++)
		disadvantages[i] = heights[i + C - 1] - heights[i];
	
	int skips = N - R*C;
	int left = 0, right = heights.back() - heights.front();
	while (left < right)
	{
		int middle = (left + right)/2;
		
		if (checkPossible(disadvantages, C, skips, middle))
			right = middle;
		else
			left = middle + 1;
	}
	
	
	std::cout << right;
	
	return 0;
}