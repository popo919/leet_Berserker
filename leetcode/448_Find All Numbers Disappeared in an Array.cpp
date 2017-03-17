#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

vector<int> findDisappearedNumbers(vector<int>& nums) {
	int size = nums.size();
	int pos = 0, cursor = 0;

	for (int i = 0; i < size; ++i)
	{
		int pos = i;
		int content = nums[pos];
		while (content != nums[content - 1])
		{
			int temp = nums[content - 1];
			nums[content - 1] = content;
			content = temp;
		}

	}

	vector<int> res;
	for (int i = 0; i < size; ++i)
		if (nums[i] != i + 1)
			res.push_back(i + 1);

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
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);

	//vector<int>& res = findDisappearedNumbers(nums);
	vector<int>& res = findDuplicates(nums);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;

	return 0;
}