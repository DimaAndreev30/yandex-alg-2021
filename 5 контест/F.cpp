#include <iostream>

#include <vector>
#include <map>


std::map<uint_fast16_t, uint_fast16_t> readModels()
{
	std::map<uint_fast16_t, uint_fast16_t> models;
	
	
	int m;
	std::cin >> m;
	
	int power, cost;
	for (int i = 0; i < m; i++)
	{
		std::cin >> power >> cost;
		
		auto alt = models.lower_bound(power);
		if (alt == models.end() or alt->second > cost)
		{
			alt = models.insert_or_assign(alt, power, cost);
			while (alt != models.begin())
			{
				--alt;
				if (alt->second >= cost)
					alt = models.erase(alt);
				else
					break;
			}
		}
	}
	
	
	return models;
}


int main()
{
	int n, m;
	
	std::cin >> n;
	std::vector<uint_fast16_t> classes(n);
	for (int i = 0; i < n; i++)
		std::cin >> classes[i];
	
	auto models = readModels();
	
	
	int result = 0;
	for (int i = 0; i < n; i++)
		result += models.lower_bound(classes[i])->second;
	
	
	std::cout << result;
	
	return 0;
}