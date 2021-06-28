#include <iostream>

#include <string>

#include <cstdint>


int main()
{
	int K;
    std::string word;
	
    std::cin >> K >> word;

    uint_fast64_t numMatches = 0, numWays = 0;
    for (int i = K; i < word.size(); ++i)
    {
        if (word[i] == word[i - K])
        {
            numMatches++;
            numWays += numMatches;
        }
        else
        {
            numMatches = 0;
        }
    }
	
	
    std::cout << numWays << std::endl;

    return 0;
}