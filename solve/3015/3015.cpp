#include <bits/stdc++.h>
using namespace std;

/*
3015 오아시스 재결합
https://www.acmicpc.net/problem/3015

스택

int = -2^-31 ~ 2 ^ 31 = 21억
long long = -2 ^ 61 ~ 2 ^ 61 = int ^ 2
ret : 1 + 2 + ... + 50만 = 50만^2 / 2 = 1250억 : int 초과
*/

stack<pair<int ,int>> stk;
int l, n, cnt;
long long ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l;
        cnt = 1;
        while (stk.size() && stk.top().first <= l)
        {
            if (stk.top().first == l) cnt += stk.top().second;
            ret += stk.top().second;
/*             for (int j = 0; j < stk.top().second; j++)
            {
                cout << stk.top().first << " - " << l << "\n";
            } */
            stk.pop();
        }
        if (stk.size())
        {
//            cout << stk.top().first << " - " << l << "\n";
            ret++;
        }
        stk.push({l, cnt});
//        cout << "====\n";
    }
    cout << ret << "\n";

    return 0;
}