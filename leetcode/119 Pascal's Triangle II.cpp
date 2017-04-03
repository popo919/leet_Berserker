#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
	vector<int> res;
	vector<int> temp;
	res.push_back(1);
	temp.push_back(1);
	for (int i = 0; i <= rowIndex; ++i)
	{
		for (int j = 1; j <= i - 1; ++j)
			temp[j] = res[j - 1] + res[j];
		if (i)
			temp.push_back(1);
		res = temp;
	}
	return res;
}


int main()
{
	vector<int> res = getRow(1);
	for (int i = 0; i < res.size(); ++i)
		printf("%d ", res[i]);
}

