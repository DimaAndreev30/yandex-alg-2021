#include <iostream>

#include <algorithm>

#include <vector>
#include <queue>


class Volunteer
{
	int time_for_balloon;
	int balloons_by_period; 
	int rest_time;
	
	int period_duration;
	
	int periods, extra_balloons;
	int next_time;
	
	
	void apply_abilities()
	{
		period_duration = time_for_balloon*balloons_by_period + rest_time;
		set_time(0);
	}
	

public:
	void set_time(int time)
	{
		auto dv = std::div(time, period_duration);
		
		periods = dv.quot;
		extra_balloons = dv.rem/time_for_balloon;
		if (extra_balloons >= balloons_by_period)
		{
			periods += 1;
			extra_balloons = 0;
		}
		
		next_time = periods*period_duration + 
				extra_balloons*time_for_balloon + time_for_balloon;
	}
	
	void next()
	{
		if (++extra_balloons == balloons_by_period)
		{
			periods += 1;
			extra_balloons = 0;
			next_time += rest_time;
		}
		next_time += time_for_balloon;
	}
	
	
	int get_next_time() const {
		return next_time;
	}
	
	int get_balloons () const {
		return periods*balloons_by_period + extra_balloons;
	}
	
	
	friend std::istream& operator>>(std::istream& in, Volunteer& vol);
};

std::istream& operator>>(std::istream& in, Volunteer& vol) {
	in >> vol.time_for_balloon >> vol.balloons_by_period >> vol.rest_time;
	vol.apply_abilities();
	
	return in;
}


struct Event
{
	int i_vol;
	int time;
	
	Event(int i, int eventTime)
		: i_vol(i)
		, time(eventTime)
	{}
};

class EventFirstToAccept
{
public:
	bool operator()(const Event& a, const Event& b) const {
			return a.time > b.time;
	}
};


int main()
{
	int M, N;
	std::cin >> M >> N;
	
	std::vector<Volunteer> volunteers(N);
	std::priority_queue<Event, std::vector<Event>, EventFirstToAccept> events;
	for (int i = 0; i < N; i++) {
		std::cin >> volunteers[i];
		events.emplace(i, volunteers[i].get_next_time());
	}
	
	
	int time = 0;
	for (int balloons = 0; balloons < M; balloons++)
	{
		int i_vol = events.top().i_vol;
		events.pop();
		
		time = std::max(time, volunteers[i_vol].get_next_time());
		volunteers[i_vol].next();
		
		events.emplace(i_vol, volunteers[i_vol].get_next_time());
	}
	
	
	std::cout << time << std::endl;
	for (int i = 0; i < N; i++)
		std::cout << volunteers[i].get_balloons() << ' ';
	
	
	return 0;
}