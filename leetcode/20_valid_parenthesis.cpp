#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if (st.empty())
		{
			st.push(s[i]);
			continue;
		}
		char top = st.top();
		if ((top == '(' && s[i] == ')') || (top == '[' && s[i] == ']') || (top == '{' && s[i] == '}'))
			st.pop();
		else
			st.push(s[i]);
	}

	return st.empty();
}

int main()
{
	isValid("[");
	return 0;
}