#include <iostream>

#include <string>
#include <unordered_set>


std::unordered_set<std::string> readSet(int n)
{
	std::string lang;
	std::unordered_set<std::string> set;
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> lang;
		set.emplace(std::move(lang));
	}
	
	return set;
}

void printSet(std::unordered_set<std::string> set)
{
	std::cout << set.size() << std::endl;
	for (auto elem : set)
		std::cout << elem << std::endl;
}


int main()
{
	int N, M;
	
	std::cin >> N >> M;
	
	auto any_known = readSet(M);
	auto all_known = any_known;
	
	std::string lang;
	for (int i = 1; i < N; i++)
	{
		std::cin >> M;
		
		std::unordered_set<std::string> all_known_update;
		for (int j = 0; j < M; j++)
		{
			std::cin >> lang;
			if (all_known.find(lang) != all_known.end())
				all_known_update.insert(lang);
			any_known.emplace(std::move(lang));
		}
		
		all_known.swap(all_known_update);
	}
	
	
	printSet(all_known);
	printSet(any_known);
	
	return 0;
}