#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
	long sum = 0, size = nums.size();
	for (auto num : nums)
		sum += num;
	long allSum = (1 + size) * size / 2;
	return allSum - sum;
}

int main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(3);
	cout << missingNumber(nums);
	return 0;
}