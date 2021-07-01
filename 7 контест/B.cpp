#include <iostream>

#include <algorithm>
#include <vector>


enum { IN = false, OUT = true };
using Event = std::pair<int, bool>;

struct NumeratedPoint
{
	int coord;
	int number;
	
	bool operator<(const NumeratedPoint& b)
	{
		return coord < b.coord;
	}
};


std::vector<int> countSegments(
		const std::vector<Event>& events,
		const std::vector<NumeratedPoint> points)
{
	std::vector<int> counts(points.size());
	
	int iPoint = 0;
	int numSegment = 0;
	for (auto [coord, flag] : events)
	{
		while (points[iPoint].coord < coord)
		{
			counts[points[iPoint].number] = numSegment;
			
			if (++iPoint >= points.size())
				return counts;
		}
		
		if (flag == IN)
			numSegment += 1;
		else // flag == OUT
			numSegment -= 1;
	}
	
	return counts;
}


int main()
{
	int N, M;
	std::cin >> N >> M;
	
	std::vector<Event> events(2*N);
	for (int i = 0; i < 2*N; )
	{
		int a, b;
		std::cin >> a >> b;
		
		if (a > b)
			std::swap(a, b);
		
		events[i] = Event(a, IN);
		i += 1;
		
		events[i] = Event(b + 1, OUT);
		i += 1;
	}
	std::sort(events.begin(), events.end());
	
	std::vector<NumeratedPoint> points(M);
	for (int i = 0; i < M; i++)
	{
		std::cin >> points[i].coord;
		points[i].number = i;
	}
	std::sort(points.begin(), points.end());
	
	
	for (auto count : countSegments(events, points))
		std::cout << count << ' ';
	
	
	return 0;
}