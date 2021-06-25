#include <iostream>
#include <fstream>

#include <string>
#include <unordered_set>


int main()
{
	std::ifstream input("input.txt");
	
	std::unordered_set<std::string> set;
	std::string word;
	while(input >> word)
	{
		set.emplace(std::move(word));
	}
	
	
	std::cout << set.size();
	
	return 0;
}