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
	int curr_time;
	
	
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
		extra_balloons = std::min(dv.rem/time_for_balloon, balloons_by_period);
		if (extra_balloons == 0)
		{
			periods -= 1;
			extra_balloons = balloons_by_period;
		}
		
		curr_time = periods*period_duration + extra_balloons*time_for_balloon;
	}
	
	void set_uptime(int time)
	{
		set_time(time + time_for_balloon);
	}
	
	
	void prev()
	{
		curr_time -= time_for_balloon;
		if (--extra_balloons == 0)
		{
			periods -= 1;
			extra_balloons = balloons_by_period;
			curr_time -= rest_time;
		}
	}
	
	
	int get_curr_time() const {
		return curr_time;
	}
	
	int get_balloons () const {
		return periods*balloons_by_period + extra_balloons;
	}
	
	double get_mean_V() const {
		return static_cast<double>(balloons_by_period)/period_duration;
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

class EventFirstToDecline
{
public:
	bool operator()(const Event& a, const Event& b) const {
			return a.time < b.time;
	}
};


int main()
{
	int M, N;
	std::cin >> M >> N;
	
	std::vector<Volunteer> volunteers(N);
	double mean_V = 0;
	for (int i = 0; i < N; i++) 
	{
		std::cin >> volunteers[i];
		mean_V += volunteers[i].get_mean_V();
	}
	
	
	int right_time = M/mean_V + 1, balloons = 0;
	std::priority_queue<Event, std::vector<Event>, EventFirstToDecline> events;
	for (int i = 0; i < N; i++)
	{
		volunteers[i].set_uptime(right_time);
		balloons += volunteers[i].get_balloons();
		
		events.emplace(i, volunteers[i].get_curr_time());
	}
	
	
	for (; balloons > M; balloons--)
	{
		int i_vol = events.top().i_vol;
		events.pop();
		
		volunteers[i_vol].prev();
		
		events.emplace(i_vol, volunteers[i_vol].get_curr_time());
	}
	
	
	int time = 0;
	for (int i = 0; i < N; i++)
		time = std::max(time, volunteers[i].get_curr_time());
	
	std::cout << time << std::endl;
	for (int i = 0; i < N; i++)
		std::cout << volunteers[i].get_balloons() << ' ';
	
	
	return 0;
}