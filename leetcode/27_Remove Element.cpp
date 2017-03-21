#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
	int p = 0, q = 0;
	while (q < nums.size() && nums[q] != val) q++;
	for (p = q; p < nums.size() && nums[p] == val; ++p);
	while (p < nums.size())
	{
		while (q < nums.size() && nums[q] != val) q++;
		for (p = q; p < nums.size() && nums[p] == val; ++p);
		if (p < nums.size() && q < nums.size())
		{
			int temp = nums[p];
			nums[p] = nums[q];
			nums[q] = temp;
		}
	}
	return q;
}

int main()
{
	vector<int> v{3,2,2,3};
	int size = removeElement(v, 3);
	printf("size %d\n", size);
	for (int i = 0; i < size; ++i)
		printf("%d\n", v[i]);
	return 0;
}