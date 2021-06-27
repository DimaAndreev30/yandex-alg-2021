#include <iostream>
#include <fstream>

#include <unordered_map>

#include <string>
#include <cctype>

#include <cstdint>


using Dictionary = std::unordered_map<std::string, uint_fast32_t>;


template<typename T>
void setBit(T& bits, int pos) {
	bits ^= (1 << pos);
}

template<typename T>
bool getBit(const T& bits, int pos) {
	return bits & (1 << pos);
}


bool isCorrect(std::string& word, const Dictionary& dictionary)
{
	int upperPos = -1;
	for (int j = 0; j < word.size(); j++)
	{
		if (std::isupper(word[j]))
		{
			if (upperPos == -1)
			{
				upperPos = j;
				word[upperPos] += 'a' - 'A';
			}
			else
			{
				return false;
			}
		}
	}
	
	if (upperPos == -1)
	{
		return false;
	}
	else
	{
		const auto it = dictionary.find(word);
		if (it == dictionary.end())
		{
			return true;
		}
		else
		{
			return getBit(it->second, upperPos);
		}
	}
}


int main()
{
	std::ifstream file("input.txt");
	
	
	int N;
	file >> N;
	
	std::string word;
	Dictionary dictionary;
	for (int i = 0; i < N; i++)
	{
		file >> word;
		
		for (int j = 0; j < word.size(); j++)
		{
			if (std::isupper(word[j]))
			{
				word[j] += 'a' - 'A';
				setBit(dictionary[word], j);
				break;
			}
		}
	}
	
	
	int result = 0;
	while (file >> word)
	{
		if (isCorrect(word, dictionary) == false)
		{
			result += 1;
		}
	}
	
	
	std::cout << result;
	
	return 0;
}

