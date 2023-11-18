#include <bits/stdc++.h>
using namespace std;

/*
9012 괄호
https://www.acmicpc.net/problem/9012

스택 사용, 구현
*/

int t;
string ps;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> ps;
        stack<int> stk;
        for (char c : ps)
        {
            if (c == '(') stk.push(1);
            else
			{
				if (!stk.empty()) stk.pop();
				else
				{
					stk.push(-1);
					break;
				}
			}
        }
        if (stk.size()) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
