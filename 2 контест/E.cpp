#include <iostream>

#include <vector>


int getHighestPlace(const std::vector<int>& list)
{
	int result = -1;
	int max_value = list[0];
	int curr_value = list[1];
	for (int i = 2; i < list.size(); i++)
	{
		if (curr_value > max_value)
		{
			max_value = curr_value;
			result = -1;
		}
		else if (list[i] < curr_value and
				result < curr_value and
				curr_value%10 == 5)
			result = curr_value;
			
		curr_value = list[i];
	}
	
	
	int place = 0;
	if (result != -1)
	{
		place = 1;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i] > result)
				place += 1;
		}
		return place;
	}
	
	return place;
}


int main()
{
	int n;
	std::cin >> n;
	
	std::vector<int> list(n);
	
	for (int i = 0; i < list.size(); i++)
		std::cin >> list[i];
	
	
	std::cout << getHighestPlace(list);
	
	return 0;
}