#include <bits/stdc++.h>
using namespace std;

/*
15684 사다리 조작
https://www.acmicpc.net/problem/15684

백트래킹
*/

int n, m, h, arr[32][12], a, b, ret = 987654321;

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        int cur = i;
        for (int j = 1; j <= h; j++)
        {
            if (arr[j][cur]) cur++;
            else if (arr[j][cur - 1]) cur--;
        }
        if (cur != i) return false;
    }
    return true;
}

void go(int depth, int cnt)
{
    if (cnt > 3 || cnt >= ret) return;
    if (check())
    {
        ret = min(ret, cnt);
        return;
    }
    for (int i = depth; i <= h; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] || arr[i][j - 1] || arr[i][j + 1]) continue;
            arr[i][j] = 1;
            go(i, cnt + 1);
            arr[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        arr[a][b] = 1;
    }
    go(1, 0);
    cout << ((ret > 3) ? -1 : ret) << "\n";

    return 0;
}