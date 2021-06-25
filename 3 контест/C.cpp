#include <iostream>

#include <algorithm>

#include <vector>
#include <set>


template<typename T>
void printSet(const T& set)
{
	std::cout << set.size() << std::endl;
	for (auto elem : set)
		std::cout << elem << ' ';
	std::cout << '\n';
}


int main()
{
	int N, M;
	std::cin >> N >> M;
	
	std::set<int> first_set;
	std::set<int> second_set;

	int value;
	for (int i = 0; i < N; i++)
	{
		std::cin >> value;
		first_set.insert(value);
	}
	for (int i = 0; i < M; i++)
	{
		std::cin >> value;
		second_set.insert(value);
	}
	
	
	std::vector<int> set_intersection;
	std::set_intersection(
			first_set.begin(), first_set.end(), 
			second_set.begin(), second_set.end(), 
			std::back_inserter(set_intersection));
	
	printSet(set_intersection);
	
	
	std::vector<int> first_set_remainings;
	std::set_difference(
			first_set.begin(), first_set.end(), 
			set_intersection.begin(), set_intersection.end(), 
			std::back_inserter(first_set_remainings));
	
	printSet(first_set_remainings);
	
	
	std::vector<int> second_set_remainings;
	std::set_difference(
			second_set.begin(), second_set.end(), 
			set_intersection.begin(), set_intersection.end(), 
			std::back_inserter(second_set_remainings));
	
	printSet(second_set_remainings);
	
	return 0;
}