#include <iostream>
#include <fstream>

#include <string>
#include <unordered_set>


using pair_t = std::pair<char, char>;


namespace std
{
	template<> struct hash<pair_t>
    {
        std::size_t operator()(pair_t const& s) const noexcept
        {
            std::size_t h1 = std::hash<char>{}(s.first);
            std::size_t h2 = std::hash<char>{}(s.second);
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };
}


int main()
{
	std::string genome;
	
	std::cin >> genome;
	
	std::unordered_multiset<pair_t> pairs_counter;
	for (int i = 1; i < genome.size(); i++)
		pairs_counter.emplace(genome[i - 1], genome[i]);
	
	
	std::cin >> genome;
	
	int result = 0;
	for (int i = 1; i < genome.size(); i++)
	{
		auto pair = std::make_pair(genome[i - 1], genome[i]);
		int count = pairs_counter.count(pair);
		if (count > 0)
		{
			result += count;
			pairs_counter.erase(pair);
		}
	}
	
	std::cout << result;
	
	return 0;
}