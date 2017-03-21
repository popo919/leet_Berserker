#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	int size = nums.size();
	int pre = nums[0];
	int res = 1;
	for (int i = 1; i < size; ++i)
	{
		if (nums[i] != pre)
			nums[res++] = nums[i];
		pre = nums[i];
	}
	return res;
}

int main()
{
	return 0;
}