#include <iostream>

#include <algorithm>
#include <vector>


enum { IN = false, OUT = true };
using Event = std::pair<int, bool>;

int getNumWatchedStudents(const std::vector<Event>& events)
{
	int numWatchedStudents = 0;
	
	int numTeachers = 0;
	for (auto [place, flag] : events)
	{
		if (numTeachers == 0)
			numWatchedStudents -= place;
		
		if (flag == IN)
			numTeachers += 1;
		else // flag == OUT
		{
			numTeachers -= 1;
			if (numTeachers == 0)
				numWatchedStudents += place + 1;
		}
	}
	
	return numWatchedStudents;
}


int main()
{
	int N, M;
	std::cin >> N >> M;
	
	std::vector<Event> events(2*M);
	for (int i = 0; i < 2*M; )
	{
		int start, end;
		std::cin >> start >> end;
		
		events[i] = Event(start, IN);
		i += 1;
		
		events[i] = Event(end, OUT);
		i += 1;
	}
	std::sort(events.begin(), events.end());
	
	
	std::cout << N - getNumWatchedStudents(events);
	
	return 0;
}