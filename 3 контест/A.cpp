#include <iostream>
#include <fstream>

#include <unordered_set>


int main()
{
	std::unordered_set<int> set;
	
	{
		std::ifstream input("input.txt");
		
		int value;
		while(input >> value)
			set.insert(value);
	}
	
	std::cout << set.size();
	
	return 0;
}