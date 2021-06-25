#include <iostream>
#include <fstream>
#include <sstream>

#include <unordered_set>
#include <set>


std::unordered_set<int> readSet()
{
	std::unordered_set<int> set;
	
	std::stringstream ss;
	{
		std::string str;
		std::getline(std::cin, str);
		ss << str;
	}
	
	int value;
	while(ss >> value)
		set.insert(value);
	
	return set;
}


int main()
{
	auto set1 = readSet();
	auto set2 = readSet();
	
	std::set<int> intersection;
	for (auto elem : set1)
	{
		if (set2.find(elem) != set2.end())
			intersection.insert(elem);
	}
	
	for (auto elem : intersection)
		std::cout << elem << ' ';
	
	return 0;
}