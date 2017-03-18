#include <iostream>
#include <vector>
#include <string>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
	int size = strs.size();
	string res;
	int p = 0;
	if (strs.size() == 0 || strs[0].size() == 0)
		return res;
	while (true)
	{
		char c = strs[0][p];
		for (int i = 0; i < size; ++i)
		{
			if (p >= strs[i].size() || strs[i][p] != c)
				return res;
		}
		res += c;
		p++;
	}

	return res;
}

int main()
{
	vector<string> v{"abcd", "abcdfg", "abvv"};
	cout << longestCommonPrefix(v) <<endl;

	return 0;
}