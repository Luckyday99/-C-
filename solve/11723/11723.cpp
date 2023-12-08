#include <bits/stdc++.h>
using namespace std;

/*
11723 집합
https://www.acmicpc.net/problem/11723

비트마스킹
*/

int m, s, inp_i;
string inp_s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> inp_s;
        if (inp_s == "all")
        {
            s = (1 << 20) - 1;
            continue;
        }
        else if (inp_s == "empty")
        {
            s = 0;
            continue;
        }
        cin >> inp_i;
        inp_i--;
        if (inp_s == "add")
        {
            s |= (1 << inp_i);
        }
        else if (inp_s == "remove")
        {
            s &= ~(1 << inp_i);
        }
        else if (inp_s == "check")
        {
            if (s & (1 << inp_i)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (inp_s == "toggle")
        {
            s ^= (1 << inp_i);
        }
    }
    return 0;
}