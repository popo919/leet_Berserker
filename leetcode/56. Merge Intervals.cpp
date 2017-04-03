#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Interval {
int start;
int end;
Interval() : start(0), end(0) {}
Interval(int s, int e) : start(s), end(e) {}
};

void Merge(Interval& a, Interval& b)
{
	a.start = a.start < b.start ? a.start : b.start;
	a.end = a.end > b.end ? a.end : b.end;
}

vector<Interval> merge(vector<Interval>& intervals) {
	sort(intervals.begin(), intervals.end(), [](Interval &a, Interval& b) {return a.start < b.start; });
	vector<Interval> res;
	int size = intervals.size();
	for(int i = 0; i < size; ++i)
	{
		int resSize = res.size();
		if(resSize == 0 || intervals[i].start > res[resSize-1].end)			
			res.push_back(intervals[i]);
		else
			Merge(res[resSize-1], intervals[i]);
	}
	return res;
}

int main()
{
	//vector<Interval> input{ {1,3}, {2,6}, {8,10}, {15,18} };
	vector<Interval> input{ { 1,4 },{ 0,0 }};
	vector<Interval> res = merge(input);
	for (auto in : res)
	{
		cout << in.start << " " << in.end << endl;
	}
}