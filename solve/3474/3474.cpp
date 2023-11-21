#include <bits/stdc++.h>
using namespace std;

/*
3474 교수가 된 현우
https://www.acmicpc.net/problem/3474

오른쪽 끝의 0의 개수 = 10이 몇번 곱해졌는지 = 2, 5가 몇번 곱해졌는지
*/

int t, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ret = 0;
        for (int i = 5; i <= n; i *= 5)
            ret += n / i;
        cout << ret << "\n";
    }
    return 0;
}