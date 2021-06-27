#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>


int main()
{
	std::ifstream file("input.txt");
	
	std::unordered_map<std::string, unsigned int> counter;
	std::string word;
	
	while (file >> word)
	{
		auto [it, _] = counter.emplace(std::move(word), 0);
		std::cout << it->second << ' ';
		it->second += 1;
	}
	
	return 0;
}
