#include <iostream>
#include <vector>
#include <functional>
using namespace std;

double recursive(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k)
{
	int size1 = nums1.size() - s1;
	int size2 = nums2.size() - s2;

	if (size1 + size2 == 1)
		return size1 ? nums1[0] : nums2[0];
	if (size2 < size1)
		return recursive(nums2, s2, nums1, s1, k);
	if (size1 == 0)
		return nums2[s2 + k - 1];
	if (size2 == 0)
		return nums1[s1 + k - 1];
	
	if (1 == k)
		return nums1[s1] < nums2[s2] ? nums1[s1] : nums2[s2];

	int p1 = k / 2 < size1 ? k / 2 : size1;
	int p2 = k - p1;

	if (nums1[s1 + p1 - 1] < nums2[s2 + p2 - 1])
		return recursive(nums1, s1 + p1, nums2, s2, k - p1);
	else
		return recursive(nums1, s1, nums2, s2 + p2, k - p2);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int size1 = nums1.size();
	int size2 = nums2.size();
	if((size1 + size2) & 0x1)
		return recursive(nums1, 0, nums2, 0, (nums1.size() + nums2.size()) / 2 + 1);
	else
		return 
		(
		recursive(nums1, 0, nums2, 0, (nums1.size() + nums2.size()) / 2)
		+
		recursive(nums1, 0, nums2, 0, (nums1.size() + nums2.size()) / 2 + 1)
			) / 2.0;
}

int (*add)(int a, int b);

int func(int a, int b, int(*add)(int a, int b))
{
	return add(a, b);
}

int main()
{
	int a = 3, b = 8;
	std::function<int(int, int)> f;
	f = [](int a, int b) 
	{
		a++;
		b++;
		return a + b; 
	};

	printf("%d", f(2,5));

	return 0;
}