#include <vector>
#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
	int size = prices.size();
	if(!size)return 0;
	int res = 0, preBuy, dir = 0;
	for(int i = 0; i < size-1; ++i)        
	{
		preBuy = prices[i];
		if(prices[i+1] > prices[i]) 
			res += prices[i+1] - preBuy;
	}
	return res;
}

int main()
{
	vector<int> v{2,1,2,0,1};
	cout << maxProfit(v);
	return 0;
}