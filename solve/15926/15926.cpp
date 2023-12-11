#include <bits/stdc++.h>
using namespace std;

/*
15926 현욱은 괄호왕이야!!
https://www.acmicpc.net/problem/15926

스택
*/

int n, ret;
stack<int> stk;
string inp;

int main()
{
    cin >> n >> inp;
    stk.push(-1);
    for (int i = 0; i < n; i++)
    {
        if (inp[i] == '(') stk.push(i);
        else
        {
            stk.pop();
            if (stk.size()) ret = max(ret, i - stk.top());
            else stk.push(i);
        }
    }
    cout << ret << '\n';
    return 0;
}