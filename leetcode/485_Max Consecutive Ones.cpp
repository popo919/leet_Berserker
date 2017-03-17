#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
	int total = 0, prev = 0, cur_total;
	int size = nums.size();
	int state = 0; // 1 up , 0 down
	nums.push_back(0);
	
	for (auto num : nums)
	{
		if (0 == prev && 1 == num)
		{
			cur_total = 0;
			state = 1;
		}
		else if (1 == prev && 0 == num)
		{
			if (cur_total > total)
				total = cur_total;
			state = 0;
		}

		if (1 == state)
			cur_total++;

		prev = num;
	}

	return total;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	cout << findMaxConsecutiveOnes(v);

	return 0;
}