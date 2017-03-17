#include <iostream>
#include <vector>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
	int total = 0;
	int size = timeSeries.size();

	if (0 == size) return 0;

	for (int i = 0; i < size - 1; ++i)
	{
		int delta = timeSeries[i + 1] - timeSeries[i];
		total += delta < duration ? delta : duration;
	}

	total += duration;
}

int main()
{


	return 0;
}