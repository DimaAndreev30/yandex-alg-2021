#include <iostream>

#include <algorithm>
#include <vector>


struct Event
{
	int city_id;
	int time;
	enum { IN = 0, OUT = 1 } type;
};

bool operator<(const Event& a, const Event& b) {
	return a.time < b.time or (a.time == b.time and a.type < b.type);
}

std::istream& operator>>(std::istream& in, Event& event)
{
	int h, m;
	
	in >> event.city_id >> h; 
	in.ignore(); 
	in >> m;
	
	event.city_id -= 1;
	event.time = 60*h + m;
	
	return in;
}


int findBusOptimalNumber(std::istream& in)
{
	int N, M;
	in >> N >> M;
	
	
	std::vector<Event> events(2*M);
	int bus_number = 0;
	for (int i = 0; i < 2*M; )
	{
		in >> events[i];
		events[i].type = Event::OUT;
		++i;
		
		in >> events[i];
		events[i].type = Event::IN;
		++i;
		
		if (events[i - 2].time > events[i - 1].time)
			bus_number += 1;
	}
	std::sort(events.begin(), events.end());
	
	
	std::vector<int> cities_bus_counter(N);
	std::vector<int> cities_least_bus_number(N);
	for (auto [city, time, type] : events)
	{
		if (type == Event::IN)
		{
			cities_bus_counter[city] += 1;
		}
		else // type == Event::OUT
		{
			cities_bus_counter[city] -= 1;
			cities_least_bus_number[city] = std::min(
					cities_least_bus_number[city], 
					cities_bus_counter[city]);
		}
	}
	
	
	for (int i = 0; i < N; i++)
	{
		if (cities_bus_counter[i] != 0)
			return -1;
		
		bus_number -= cities_least_bus_number[i];
	}
	
	return bus_number;
}


int main()
{
	std::cout << findBusOptimalNumber(std::cin);
	
	return 0;
}