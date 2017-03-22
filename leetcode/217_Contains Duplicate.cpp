#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end(), [=](int a, int b) {return a < b; });
	if (nums.size() == 0) return false;
	int pre = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == pre++)
			return false;
	}
	return true;
}

int main()
{

	return 0;
}