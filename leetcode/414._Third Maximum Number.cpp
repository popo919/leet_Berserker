#include <iostream>
#include <vector>
using namespace std;

int thirdMax(vector<int>& nums) {
	int min = nums[0];
	for (int i = 1; i < nums.size(); ++i)
		if (min > nums[i])
			min = nums[i];

	int max = min, second = min, third = min;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > max)
		{
			third = second;
			second = max;
			max = nums[i];
		}
		else if (nums[i] < max && nums[i] > second)
		{
			third = second;
			second = nums[i];
		}
		else if (nums[i] < second && nums[i] > third)
			third = nums[i];
	}

	if (third == second)
		return max;
	else
		return third;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	cout << thirdMax(nums) << endl;

	return 0;
}