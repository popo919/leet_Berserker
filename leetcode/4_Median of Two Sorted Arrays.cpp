#include<iostream>
#include<vector>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	
	int p1 = 0, p2 = 0;
	int size1 = nums1.size();
	int size2 = nums2.size();
	int total = size1 + size2;
	int median = total % 2 ? total / 2 + 1 : total / 2;

	if (total == 1)
		return size1 ? nums1[0] : nums2[0] ;

	while (median != 1)
	{
		size1 = nums1.size() - p1;
		size2 = nums2.size() - p2;

		//int median = total / 2;
		int medianHalf = median / 2;

		if (size1 >= medianHalf && size2 >= median - medianHalf)
		{
			if (nums1[p1 + medianHalf - 1] < nums2[p2 + median - medianHalf - 1]) // delete medianHalf elems
			{
				p1 += medianHalf;
				median -= medianHalf;
			}
			else
			{
				p2 += median - medianHalf;
				median = medianHalf;
			}
		}
		else if (size1 < medianHalf)
		{
			if (size1 == 0 || nums1[p1 + size1 - 1] < nums2[p2 + median - size1 - 1])
			{
				p1 += size1;
				p2 += median - size1 - 1;

				if (total % 2 == 1)
					return nums2[p2];
				else
					return (nums2[p2] + nums2[p2 + 1]) / 2.0f;
				
			}
			else
			{
				p2 += median - size1;
				median = size1;
			}
			
		}
		else if (size2 < median - medianHalf)
		{
			if (size2 == 0 || nums2[p2 + size2 - 1] < nums1[p1 + median - size2 - 1])
			{
				p2 += size2;
				p1 += median - size2 - 1;

				if (total % 2 == 1)
					return nums1[p1];
				else
					return (nums1[p1] + nums1[p1 + 1]) / 2.0f;

			}
			else
			{
				p1 += median - size2;
				median = size2;
			}
			
		}
	}
	
	double preRes = 100000000.0, res = 100000000.0;

	if (total % 2 == 1)
	{
		if (p1 < nums1.size())
			preRes = nums1[p1];
		if (p2 < nums2.size() && nums2[p2] < preRes)
			preRes = nums2[p2];

		return preRes;
	}
	else
	{
		int flag = 1;
		if (p1 < nums1.size())
			preRes = nums1[p1];
		if (p2 < nums2.size() && nums2[p2] < preRes)
		{
			preRes = nums2[p2];
			flag = 2;
		}

		if (flag == 1)
		{
			double temp = 100000000.0;
			if (p2 < nums2.size())
				res = nums2[p2];
			if (p1 + 1 < nums1.size())
				temp = nums1[p1 + 1];

			if (temp < res)
				res = temp;
		}
		else
		{
			double temp = 100000000.0;
			if (p2 + 1 < nums2.size())
				res = nums2[p2 + 1];
			if (p1 < nums1.size() && nums1[p1] < res)
				temp = nums1[p1];

			if (temp < res)
				res = temp;
		}

		return (preRes + res) / 2.0;
	}
	
}

int main()
{
	vector<int> nums1, nums2;
	//nums2.push_back(1);
	nums1.push_back(2);
	/*nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(4);*/

	double res = findMedianSortedArrays(nums1, nums2);
	printf("%.1lf", res);

	return 0;
}