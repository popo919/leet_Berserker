#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
	int cur = 0;
	int num = 1, pre = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		if (pre == nums[i])
			num++;
		else
		{
			num--;
			if (num == 0)
				pre = nums[i];
		}
	}

	return pre;
}

int main()
{

	return 0;
}