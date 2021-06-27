#include <iostream>
#include <fstream>

#include <unordered_set>
#include <unordered_map>

#include <string>
#include <cctype>

#include <algorithm>


using Dictionary = std::unordered_set<std::string>;


bool readYesNo(std::ifstream& file)
{
	std::string input;
	file >> input;
	
	if (input == "YES")
	{
		return true;
	}
	else
	{
		return false;
	}
}


void makeLower(std::string& str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = std::tolower(str[i]);
}


Dictionary readKeyWords(std::ifstream& file, int n, bool isCaseDependence)
{
	std::unordered_set<std::string> keyWords;
	
	std::string word;
	for (int i = 0; i < n; i++)
	{
		file >> word;
		
		if (isCaseDependence == false)
			makeLower(word);
		
		keyWords.emplace(std::move(word));
	}
	
	return keyWords;
}


bool readItem(const std::string& line, int& pos, std::string& item,
			  const Dictionary& keyWords, bool isFirstDigitAllowed)
{
	int lastDelim = pos - 1;
	for (; pos != line.size(); pos++)
	{
		if (std::isalpha(line[pos]) or
			line[pos] == '_')
		{
			for (pos++; pos != line.size(); pos++)
			{
				if (std::isalpha(line[pos]) == false and
					std::isdigit(line[pos]) == false and
					line[pos] != '_')
				{
					break;
				}
			}
			
			if (isFirstDigitAllowed == true or
				std::isdigit(line[lastDelim + 1]) == false)
			{
				item = std::string(line, lastDelim + 1, pos - lastDelim - 1);
				return true;
			}
			else
			{
				lastDelim = pos;
			}
		}
		else if (std::isdigit(line[pos]) == false)
		{
			lastDelim = pos;
		}
	}
	
	return false;
}


void printMostCommon(std::ifstream& file, const Dictionary& keyWords, 
					 bool isCaseDependence, bool isFirstDigitAllowed)
{
	std::unordered_map<std::string, unsigned> itemsCounter;
	
	std::string line, item;
	while(std::getline(file, line))
	{
		if (isCaseDependence == false)
			makeLower(line);
		
		int pos = 0;
		while (readItem(line, pos, item, keyWords, isFirstDigitAllowed))
		{
			itemsCounter[std::move(item)] += 1;
		}
	}
	
	
	auto max = itemsCounter.cbegin();
	for (auto it = itemsCounter.cbegin(); it != itemsCounter.cend(); it++)
	{
		if (max->second < it->second or
				(max->second == it->second and
				 max->first > it->first))
			max = it;
	}
	
	std::cout << max->first;
}


int main()
{
	std::ifstream file("input.txt");
	
	
	int n;
	file >> n;
	
	bool isCaseDependence = readYesNo(file), 
	     isFirstDigitAllowed = readYesNo(file);
	
	auto keyWords = readKeyWords(file, n, isCaseDependence);
	
	printMostCommon(file, keyWords, isCaseDependence, isFirstDigitAllowed);
								
	return 0;
}

