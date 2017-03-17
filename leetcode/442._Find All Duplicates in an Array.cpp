#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
	int size = nums.size();
	vector<int> res;

	for (int i = 0; i < size; ++i)
	{
		int abs = nums[i] < 0 ? -nums[i] : nums[i];
		if (nums[abs - 1] < 0)
			res.push_back(abs);
		nums[abs - 1] = -nums[abs - 1];
	}

	return res;
}

int main()
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);

	auto res = findDuplicates(nums);

	for (auto num : res)
	{
		std::cout << num << std::endl;
	}

	return 0;
}