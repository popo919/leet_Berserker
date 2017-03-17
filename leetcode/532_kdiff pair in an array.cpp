#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPairs(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end(), [](int a, int b) {return a < b; });

	int size = nums.size();
	int res = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
			if (nums[j] - nums[i] == k)
			{
				res++; break;
			}
			else if (nums[j] - nums[i] > k)
				break;
		while (i < size - 1 && nums[i] == nums[i + 1])i++;
	}

	return res;
}

int main()
{
	vector<int> input{ 3, 1, 4, 1, 5 };
	printf("%d", findPairs(input, 2));
	return 0;
}