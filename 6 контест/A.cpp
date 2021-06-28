#include <iostream>

#include <vector>


bool contains(const std::vector<int>& array, int value)
{
	for (int left = 0, right = array.size(); left < right; )
	{
		int middle = (left + right)/2;
		if (array[middle] < value)
			left = middle + 1;
		else if (array[middle] > value)
			right = middle;
		else
			return true;
	}
	
	return false;
}


int main()
{
	int N, K;
	std::cin >> N >> K;
	
	std::vector<int> array(N);
	for (int i = 0; i < N; i++)
		std::cin >> array[i];
	
	
	for (int i = 0; i < K; i++)
	{
		int value;
		std::cin >> value;
		if (contains(array, value))
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	
	return 0;
}