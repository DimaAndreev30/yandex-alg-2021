#include <iostream>

#include <algorithm>
#include <vector>


const int DAY_START = 0;
const int DAY_LENGTH = 10000;

using TimeInterval = std::pair<int, int>;


bool checkSecurity(const std::vector<TimeInterval>& intervals)
{
	if (intervals.front().first > 0 or 
			intervals.back().second < DAY_LENGTH)
		return false;
	
	int prev_out = -1;
	for (int i = 1; i < intervals.size(); i++)
	{
		if (prev_out >= intervals[i].first)
			return false;
		
		prev_out = intervals[i - 1].second;
		
		if (intervals[i].first > prev_out or
				prev_out >= intervals[i].second) 
			return false;
	}
	
	return true;
}


int main()
{
	int K;
	std::cin >> K;
	
	for (int i = 0; i < K; i++)
	{
		int N;
		std::cin >> N;
		
		std::vector<TimeInterval> intervals(N);
		for (int j = 0; j < N; j++) {
			std::cin >> intervals[j].first >> intervals[j].second;
		}
		std::sort(intervals.begin(), intervals.end());
		
		
		if (checkSecurity(intervals))
			std::cout << "Accepted" << std::endl;
		else
			std::cout << "Wrong Answer" << std::endl;
	}
	
	return 0;
}