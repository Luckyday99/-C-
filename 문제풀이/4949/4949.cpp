#include <bits/stdc++.h>
using namespace std;

/*
4949 균형잡힌 세상
https://www.acmicpc.net/problem/4949

스택사용, 구현, 9012랑 비슷함
*/

string inp;

int main()
{
    while (true)
    {
        stack<char> stk;
        getline(cin, inp);
        if (inp == ".") break;
        for (char c : inp)
        {
            if (c == '(' || c == '[') stk.push(c);
            if (c == ')')
            {
				if (stk.empty() || stk.top() == '[')
				{
					stk.push('x');
					break;
				}
				else stk.pop();
            }
            else if (c == ']')
            {
				if (stk.empty() || stk.top() == '(')
				{
					stk.push('x');
					break;
				}
				else stk.pop();
            }
        }
        if (stk.size()) cout << "no\n";
        else cout << "yes\n";
    }

    return 0;
}
