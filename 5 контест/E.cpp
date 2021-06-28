#include <iostream>

#include <vector>


int main()
{
	int N, K;
	std::cin >> N >> K;
	
	std::vector<int> kind(N), counter(K);
	for (int i = 0; i < N; i++)
	{
		std::cin >> kind[i];
		kind[i] -= 1;
	}
	
	
	int min = N, l_min = 0, r_min = N;
	int kindIn = 0;
	for (int l = 0, r = 0; r < N; )
	{
		if (counter[kind[r]] == 0)
			kindIn += 1;
		counter[kind[r]] += 1;
		r++;
		
		if (kindIn == K)
		{
			while(counter[kind[l]] > 1)
			{
				counter[kind[l]] -= 1;
				l++;
			}
			
			if (min > r - l)
			{
				min = r - l;
				l_min = l;
				r_min = r;
			}
			
			kindIn -= 1;
			counter[kind[l]] -= 1;
			l++;
		}
	}
	
	
	std::cout << l_min + 1 << ' ' << r_min << std::endl;
	
	return 0;
}