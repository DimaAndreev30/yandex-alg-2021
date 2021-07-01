#include <iostream>

#include <algorithm>
#include <vector>


enum { IN = false, OUT = true };
using Event = std::pair<int, bool>;


int getWorktime(const std::vector<Event>& events, int N)
{
	if (N == 0)
		return 24*60;
	
	
	int worktime = 0;
	
	int numOpens = 0;
	for (auto [time, flag] : events)
	{
		if (flag == IN)
		{
			numOpens += 1;
			if (numOpens == N)
				worktime -= time;
		}
		else // flag == OUT
		{
			if (numOpens == N)
				worktime += time;
			numOpens -= 1;
		}
	}
	
	return worktime;
}


int readTime()
{
	int h, m;
	std::cin >> h >> m;
	return 60*h + m;
}

void writeEvent(std::vector<Event>& events, int& pos, int inTime, int outTime)
{
	events[pos] = Event(inTime, IN);
	++pos;
	
	events[pos] = Event(outTime, OUT);
	++pos;
}


int main()
{
	int N;
	std::cin >> N;
	
	std::vector<Event> events(4*N);
	int pos = 0, numFullTime = 0;
	for (int i = 0; i < N; i++)
	{
		int inTime = readTime(), outTime = readTime();
		
		if (inTime != outTime)
		{
			if (inTime < outTime)
			{
				writeEvent(events, pos, inTime, outTime);
			}
			else
			{
				writeEvent(events, pos, inTime, 24*60);
				writeEvent(events, pos, 0, outTime);
			}
		}
		else
			numFullTime += 1;
	}
	events.resize(pos);
	std::sort(events.begin(), events.end());
	
	
	std::cout << getWorktime(events, N - numFullTime);
	
	
	return 0;
}