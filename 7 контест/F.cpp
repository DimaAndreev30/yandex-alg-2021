#include <iostream>


#include <algorithm>

#include <vector>
#include <unordered_set>


struct Date
{
	int year;
	short month;
	short day;
	
	
	bool operator<(const Date& b) const {
		return year < b.year or (year == b.year and 
				(month < b.month or (month == b.month and
				(day < b.day))));
	}
	
	friend std::istream& operator>>(std::istream& in, Date& date);
};	

std::istream& operator>>(std::istream& in, Date& date) {
	return in >> date.day >> date.month >> date.year;
}


struct Event
{
	Date date;
	int number;
	enum Type{ OUT = 0, IN = 1 } type;
	
	
	bool operator<(const Event& b) const {
		return date < b.date or ((not (b.date < date)) and type < b.type);
	}
};

void printAllMaxGroups(const std::vector<Event>& events)
{
	if (events.size() == 0)
		std::cout << 0;
	else
	{
		std::unordered_set<int> group;

		bool isUpdated = false;
		for (auto &[date, number, eventType] : events)
		{
			if (eventType == Event::IN)
			{
				group.insert(number);
				isUpdated = true;
			}
			else // eventT == Event::OUT
			{
				if (isUpdated)
				{
					for (auto number : group)
						std::cout << number << ' ';
					std::cout << std::endl;
					
					isUpdated = false;
				}
				group.erase(number);
			}
		}
	}
}


int main()
{
	int N;
	std::cin >> N;
	
	std::vector<Event> events(2*N);
	Date lowAge, highAge;
	int pos = 0;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> lowAge >> highAge;
		
		lowAge.year += 18;
		if (lowAge < highAge)
		{
			events[pos] = {lowAge, i, Event::IN};
			pos += 1;
			
			lowAge.year += 62;
			events[pos] = {std::min(lowAge, highAge), i, Event::OUT};
			pos += 1;
		}
	}
	events.resize(pos);
	std::sort(events.begin(), events.end());
	
	
	printAllMaxGroups(events);
	
	return 0;
}