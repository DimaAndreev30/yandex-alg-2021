#include <iostream>
#include <fstream>

#include <map>
#include <string>

#include <cstdint>


int main()
{
	std::ifstream file("input.txt");
	
	std::map<std::string, std::map<std::string, uint_fast64_t> > customers_info;
	
	std::string customer, product;
	uint_fast64_t count;
	while (file >> customer >> product >> count)
		customers_info[customer][product] += count;
	
	for (const auto &[customer, customer_info] : customers_info)
	{
		std::cout << customer << ":\n";
		for (const auto &[product, count] : customer_info)
		{
			std::cout << product << ' ' << count << std::endl;
		}
	}
	
	
	return 0;
}

