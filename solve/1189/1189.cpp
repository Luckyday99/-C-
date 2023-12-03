#include <bits/stdc++.h>
using namespace std;

/*
1189 컴백홈
https://www.acmicpc.net/problem/1189

dfs?, 백트래킹
*/

using pii = pair<int, int>;
int r, c, k, ret, v[8][8];
char arr[8][8];
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

void go(int cnt, int y, int x)
{
    v[y][x] = true;
    if (cnt == k)
    {
        if (y == 1 && x == c) ret++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny <= 0 || nx <= 0 || ny > r || nx > c || v[ny][nx]) continue;
        if (arr[ny][nx] == '.')
        {
            go(cnt + 1, ny, nx);
            v[ny][nx] = false;
        }
    }
}

int main()
{
    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
        }
    }
    go (1, r, 1);
    cout << ret << "\n";

    return 0;
}