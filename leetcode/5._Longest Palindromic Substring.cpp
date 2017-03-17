#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int GetIndex(int i, int j)
{
	return j * (j + 1) / 2 + i;
}

void PrintTriangle(bool* state, int len)
{
	for (int j = 0; j < len; ++j)
	{
		for (int i = 0; i < j + 1; ++i)
		{
			printf("%d ", state[GetIndex(i, j)] ? 1 : 0);
		}

		printf("\n");
	}
}

string longestPalindrome(string s) {
	int st = 0, resLen = 1;
	int len = s.length();
	bool *state = new bool[len * (len + 1) / 2];
	fill(state, state + len * (len + 1) / 2, 0);
	for (int i = 0; i < len; ++i)
		state[GetIndex(i, i)] = true;
	for (int i = 0; i < len - 1; ++i)
	{
		if (s[i] == s[i + 1])
		{
			state[GetIndex(i, i + 1)] = true;
			resLen = 2;
			st = i;
		}
	}

	//PrintTriangle(state, s.length());

	for (int j = 2; j < len; ++j)
	{
		for (int i = 0; i < len - j; ++i)
		{
			if (s[i] != s[i + j])
				state[GetIndex(i, i+j)] = false;
			else if (state[GetIndex(i + 1, i + j - 1)])
			{
				state[GetIndex(i, i + j)] = true;
				if (j + 1 > resLen)
				{
					resLen = j + 1;
					st = i;
				}
			}

			//PrintTriangle(state, s.length());
		}
	}

	return s.substr(st, resLen);
}

int main()
{
	string s = "ccc";
	cout << longestPalindrome(s) << endl;
	return 0;
}