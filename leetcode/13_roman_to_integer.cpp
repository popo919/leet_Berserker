#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num[300];

int romanToInt(string s) {
	int res = 0, i = 0;
	for (i = 0; i < s.size() - 1; ++i)
	{
		res += (num[s[i]] < num[s[i + 1]] ? -1 : 1) * num[s[i]];
	}
	res += num[s[i]];
	return res;
}

int main()
{
	num['I'] = 1;
	num['V'] = 5;
	num['X'] = 10;
	num['L'] = 50;
	num['C'] = 100;
	num['D'] = 500;
	num['M'] = 1000;

	printf("%d", romanToInt("MCMXCVI"));
	return 0;
}