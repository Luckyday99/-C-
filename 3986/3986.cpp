#include <bits/stdc++.h>
using namespace std;

/*
3986 좋은 단어
https://www.acmicpc.net/source/share/1797670218184cc385194f46b1b967dd

stack : 후입선출, push, pop 
*/

int n, cnt;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (!str.length() % 2) break;
		stack<char> stk;
		for (char c : str)
		{
			if (stk.size() && stk.top() == c) stk.pop();
			else stk.push(c);
		}
		if (stk.size() == 0) cnt++;
	}
	cout << cnt << "\n";
	
	return 0;
 }
