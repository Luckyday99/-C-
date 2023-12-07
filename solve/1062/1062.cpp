#include <bits/stdc++.h>
using namespace std;

/*
1062 가르침
https://www.acmicpc.net/problem/1062

비트마스킹, 백트래킹
알파벳 = 26길이 비트마스킹으로 나타내기 쉽다.
*/

int n, k, words[52], ret;
string s;
vector<int> masks;

void make_mask(int start, int cnt, int mask)
{
    if (cnt == k
    && mask & (1 << ('a' - 'a'))
    && mask & (1 << ('n' - 'a'))
    && mask & (1 << ('t' - 'a'))
    && mask & (1 << ('i' - 'a'))
    && mask & (1 << ('c' - 'a')))
    {
        masks.push_back(mask);
        return;
    }
    for (int i = start; i < 26; i++)
    {
        make_mask(i + 1, cnt + 1, mask |= (1 << i));
        mask &= ~(1 << i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (char c : s) words[i] |= (1 << (c - 'a'));
    }
    if (k < 5)
    {
        cout << 0 << "\n";
        return 0;
    }
    make_mask(0, 0, 0);
    for (int mask : masks)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if ((words[i] & ~mask) == 0) cnt++;
        }
        ret = max(ret, cnt);
    }
    cout << ret << "\n";

    return 0;
}