#include <iostream>
#include <vector>
using namespace std;

struct Interval {
int start;
int end;
Interval() : start(0), end(0) {}
Interval(int s, int e) : start(s), end(e) {}
};

int BiSearch(vector<Interval>& intervals, int curStart)
{
	int size = intervals.size(), st = 0, ed = size-1, mid;
	while(st <= ed)
	{
		mid = (st + ed) / 2;
		if(intervals[mid].start <= curStart)
			st = mid+1;
		else
			ed = mid-1;
	}
	return st-1;
}

void Merge(Interval& a, Interval& b)
{
	a.start = a.start < b.start ? a.start : b.start;
	a.end = a.end > b.end ? a.end : b.end;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	int idx = BiSearch(intervals, newInterval.start), size = intervals.size();
	Interval cur = newInterval;
	vector<Interval> res;
	if (size == 0)
	{
		res.push_back(newInterval);
		return res;
	}
	
	for(int i = 0; i <= idx; ++i) // push pre elements
		res.push_back(intervals[i]);
	if(res.size() == 0 || newInterval.start > res[res.size()-1].end) // merge or push new elem
		res.push_back(newInterval);
	else
		Merge(res[res.size() - 1], newInterval);
	for(int i = idx+1; i < size; ++i)
	{
		if(intervals[i].start <= res[res.size()-1].end)
			Merge(res[res.size()-1], intervals[i]);
		else
			res.push_back(intervals[i]);
	}
	return res;
}

int main()
{
	//vector<Interval> input{ {1,3}, {6,9} };
	//vector<Interval> input{ { 1,2 },{ 3,5 },{6,7},{8,10},{12,16} };
	vector<Interval> input{ { 1,5 }};
	vector<Interval> res = insert(input, {0,3});
	for (auto r : res)
	{
		cout << r.start << " " << r.end << endl;
	}
	return 0;
}