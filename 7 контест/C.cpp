#include <iostream>

#include <algorithm>
#include <vector>


struct NumeratedPoint
{
	int place;
	int number;
	
	bool operator<(const NumeratedPoint& b)
	{
		return place < b.place;
	}
};


int getVariants (const std::vector<NumeratedPoint>& events, int D)
{
	int variants = 0;
	
	for (int left = 0, right = 0; right < events.size(); left++)
	{
		int rightBorder = events[left].place + D;
		while (++right < events.size() and
				events[right].place <= rightBorder)
			{}
		
		variants = std::max(variants, right - left);
	}
	
	return variants;
}


int main()
{
	int N, D;
	std::cin >> N >> D;
	
	std::vector<NumeratedPoint> events(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> events[i].place;
		events[i].number = i;
	}
	std::sort(events.begin(), events.end());
	
	
	int variants = getVariants(events, D);
	std::vector<int> tickets(N);
	for (int i = 0; i < N; i++)
		tickets[events[i].number] = 1 + i%variants;
	
	
	std::cout << variants << std::endl;
	for (int i = 0; i < N; i++)
		std::cout << tickets[i] << ' ';
	
	return 0;
}