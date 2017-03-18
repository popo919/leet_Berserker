#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Num
{
	int index;
	int val;
};


bool containsNearbyDuplicate(vector<int>& nums, int k) {
	vector<Num> numVec;
	int size = nums.size();
	for (int i = 0; i < size; ++i)
	{
		Num num{i, nums[i]};
		numVec.push_back(num);
	}
	sort(numVec.begin(), numVec.end(), 
	[](Num n1, Num n2) 
	{if (n1.val != n2.val)
		return n1.val < n2.val;
	else
		return n1.index < n2.index; });
	int i = 0;
	while (i < size)
	{
		int j = 0;
		for (j = i + 1; j < size && numVec[j].val == numVec[i].val; ++j)
		{
			if (numVec[j].index - numVec[j-1].index <= k)
				return true;
		}
		i = j;
	}
	return false;
}

int main()
{
	vector<int> v{1,0,1,1};
	printf("%d", containsNearbyDuplicate(v, 1));
	return 0;
}