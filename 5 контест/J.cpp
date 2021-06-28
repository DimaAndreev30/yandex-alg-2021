#include <iostream>

#include <vector>
#include <unordered_set>

#include <algorithm>
#include <cstdint>


struct Point
{
	int x;
	int y;
	
	
	uint_fast64_t adjust(const Point& b)
	{
		x -= b.x;
		y -= b.y;
		
		return static_cast<int_fast64_t>(x)*x + static_cast<int_fast64_t>(y)*y;
	}
	
	Point operator-()
	{
		return {-x, -y};
	}
};
	
bool operator==(const Point& a, const Point& b)
{
	return a.x == b.x and a.y == b.y;
}


namespace std
{
	template<> struct hash<Point>
    {
        std::size_t operator()(Point const& point) const noexcept
        {
            std::size_t h1 = std::hash<int>{}(point.x);
            std::size_t h2 = std::hash<int>{}(point.y);
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };
}


int main()
{
	int n;
	std::cin >> n;
	
	std::vector<Point> points(n);
	for (int i = 0; i < n; i++)
		std::cin >> points[i].x >> points[i].y;
	
	
	uint_fast64_t regularTrCount = 0, degenTrCount = 0;
	
	std::vector<uint_fast64_t> distances(n);
	std::unordered_set<Point> visited;
	for (auto point : points)
	{
		for (int i = 0; i < n; i++)
		{
			distances[i] = points[i].adjust(point);
			if (visited.find(-points[i]) == visited.end())
				visited.insert(points[i]);
			else
				degenTrCount += 1;
		}
		
		std::sort(distances.begin(), distances.end());
		
		for (int left = 1, right = 2; right < n; left = right, right++)
		{
			while (right < n and distances[left] == distances[right])
				right++;
			
			uint_fast64_t count = right - left;
			regularTrCount += count*(count - 1)/2;
		}
		
		visited.clear();
	}
	
	regularTrCount -= degenTrCount;
	
	
	std::cout << regularTrCount;
	
	return 0;
}