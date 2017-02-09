#include <iostream>
#include <vector>
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

int main()
{
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(4);
	v1.push_back(9);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(11);

	printf("%.1lf", findMedianSortedArrays(v1, v2));

	return 0;
}