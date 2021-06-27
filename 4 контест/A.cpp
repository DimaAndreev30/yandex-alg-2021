#include <iostream>
#include <string>
#include <unordered_map>


int main()
{
	int N;
	std::unordered_map<std::string, std::string> synonym;
	std::string word1, word2;
	
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> word1 >> word2;
		
		synonym[word1] = word2;
		synonym[word2] = word1;
	}
	
	std::string word;
	std::cin >> word;
	std::cout << synonym[word];
	
	return 0;
}
