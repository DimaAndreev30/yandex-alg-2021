#include <iostream>

#include <vector>

#include <cstdint>


using Sequence = std::vector<int_fast16_t>;

int getLeftMedian(const Sequence& a, const Sequence& b, int L)
{
	if (a.back() <= b.front())
		return a.back();
	if (b.back() <= a.front())
		return b.back();
	
	int left = 0, right = L - 1;
	while (true)
	{
		int a_middle = (left + right)/2, b_middle = L - a_middle - 2;
		if (a[a_middle] >= b[b_middle])
		{
			if (a[a_middle] <= b[b_middle + 1])
				return a[a_middle];
			right = a_middle;
		}
		else
		{
			if (b[b_middle] <= a[a_middle + 1])
				return b[b_middle];
			left = a_middle + 1;
		}
	}
}


int main()
{
	int N, L;
	std::cin >> N >> L;
	
	std::vector<Sequence> sequences(N, Sequence(L));
	for (auto &seq : sequences)
		for (int j = 0; j < L; j++)
			std::cin >> seq[j];
		
		
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			std::cout << getLeftMedian(sequences[i], sequences[j], L) << std::endl;
		
	return 0;
}