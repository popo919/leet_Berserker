#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
	int p = 0, q = 0;
	while (nums[p] != 0) p++;
	q = p;
	while (nums[q] == 0) q++;

	while (p < nums.size() && q < nums.size())
	{
		int temp = nums[p];
		nums[p] = nums[q];
		nums[q] = temp;
		p++;
		while (q < nums.size() && nums[q] == 0) q++;
	}
}

int main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(12);
	moveZeroes(nums);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << " ";
	}
	return 0;
}