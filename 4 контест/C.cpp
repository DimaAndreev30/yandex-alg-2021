#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

#include <tuple>


int main()
{
	std::ifstream file("input.txt");
	
	std::unordered_map<std::string, unsigned int> counter;
	std::string word;
	
	while (file >> word)
	{
		auto [it, _] = counter.emplace(std::move(word), 0);
		it->second += 1;
	}
	
	
	auto curr_it = counter.begin();
	for (auto it = ++counter.begin(); it != counter.end(); it++)
	{
		if (curr_it->second < it->second or
				(curr_it->second == it->second and
				 curr_it->first > it->first))
			curr_it = it;
	}
	
	std::cout << curr_it->first;
	
	return 0;
}
