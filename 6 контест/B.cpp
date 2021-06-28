#include <iostream>

#include <vector>


int findClosest(const std::vector<int>& array, int value)
{
	if (array.front() >= value) return array.front();
	if (array.back () <= value) return array.back();
	
	int left = 1, right = array.size() - 1;
	while (left < right)
	{
		int middle = (left + right)/2;
		if (array[middle] < value)
			left = middle + 1;
		else if (array[middle] > value)
			right = middle;
		else
			return value;
	}
	
	left -= 1;
	if (static_cast<unsigned>(value - array[left]) <= 
		static_cast<unsigned>(array[right] - value))
		return array[left];
	else
		return array[right];
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
		std::cout << findClosest(array, value) << std::endl;
	}
	
	return 0;
}