#include <iostream>
using namespace std;

int strStr(string haystack, string needle) {
	if (needle.size() == 0) return 0;
	if (haystack.size() < needle.size()) return -1;
	for (int i = 0; i < haystack.size() - needle.size(); ++i)
	{
		bool flag = true;
		for (int j = 0; i+j < haystack.size() && j < needle.size(); ++j)
		{
			if (haystack[i + j] != needle[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			return i;
	}
	return -1;
}

int main()
{

	return 0;
}