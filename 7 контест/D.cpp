#include <iostream>

#include <algorithm>

#include <vector>
#include <queue>


const int ADV_N = 2;
const int ADV_LENGTH = 5;


struct TimePeriod
{
	int start;
	int end;
	
	
	bool operator<(const TimePeriod& b) const noexcept
	{
		return start < b.start;
	}
	
	friend std::istream& operator>>(std::istream& in, TimePeriod& period);
};


std::istream& operator>>(std::istream& in, TimePeriod& period) {
	in >> period.start >> period.end;
	return in;
}


struct AdvPlacement
{
	int numSpec;
	std::vector<int> advIns;
	
	AdvPlacement(int maxDepth)
		: numSpec(0)
		, advIns(maxDepth)
	{}
};


void findBestAdvPlacement(
		const std::vector<TimePeriod>& periods,
		AdvPlacement& advPlacement,
		int iPeriod=0, int advInLimit=1)
{
	int depth = advPlacement.advIns.size();
	advPlacement.numSpec = 0;
	if (depth > 0)
		for (int i = 0; i < depth; i++)
			advPlacement.advIns[i] = advInLimit + ADV_LENGTH*i;
	else
		return;
	
	
	std::priority_queue<int, std::vector<int>, std::greater<int> > advOuts;
	AdvPlacement nextAdv(depth - 1);
	for (; iPeriod < periods.size(); iPeriod++)
	{
		int advIn = std::max(advInLimit, periods[iPeriod].start);
		int advOut = periods[iPeriod].end - ADV_LENGTH;
		if (advIn <= advOut)
		{
			advOuts.push(advOut);
			while (advIn > advOuts.top())
				advOuts.pop();
			
			
			if (depth > 1)
				findBestAdvPlacement(
						periods, nextAdv,
						iPeriod + 1, advIn + ADV_LENGTH);
					
			int newNumSpec = advOuts.size() + nextAdv.numSpec;
			if (advPlacement.numSpec < newNumSpec)
			{
				advPlacement.numSpec = newNumSpec;
				advPlacement.advIns[0] = advIn;
				for (int i = 1; i < depth; i++)
					advPlacement.advIns[i] = nextAdv.advIns[i - 1];
			}
		}
	}
}


int main()
{
	int N;
	std::cin >> N;
	
	std::vector<TimePeriod> periods(N);
	for (int i = 0; i < N; i++)
		std::cin >> periods[i];
	std::sort(periods.begin(), periods.end());
	
	
	AdvPlacement advPlacement(ADV_N);
	findBestAdvPlacement(periods, advPlacement);
	
	std::cout << advPlacement.numSpec << ' ';
	for (int i = 0; i < ADV_N; i++)
		std::cout << advPlacement.advIns[i] << ' ';
	
	
	return 0;
}