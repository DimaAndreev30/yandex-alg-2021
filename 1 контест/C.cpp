#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <array>

#include <cctype>


using phone_t = std::array<char, 11>;


phone_t readPhone(std::istream& input)
{
	phone_t number{"8495"};
	
	std::string str;
	std::getline(input, str);
	
	for (int i = str.size() - 1, k = 10; i >= 0; i--)
	{
		if (std::isdigit(str[i]))
		{
			number[k] = str[i];
			k--;
			if (k <= 0)
				break;
		}
	}
	
	return number;
}


void run()
{
	phone_t number = readPhone(std::cin);
	
	for (int i = 0; i < 3; i++)
	{
		phone_t given_number = readPhone(std::cin);
		if (number == given_number)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}


int main()
{
	run();
	
	return 0;
}