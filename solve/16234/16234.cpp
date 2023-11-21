#include <bits/stdc++.h>
using namespace std;

/*
16234 인구 이동
https://www.acmicpc.net/problem/16234

dfs, 브루트포스
*/

int n, l, r, arr[54][54], visited[54][54], people, ret;
vector<pair<int, int>> opened_yx;
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1 ,0 };

void dfs (int y, int x)
{
    visited[y][x] = true;
    opened_yx.push_back(make_pair(y, x));
    people += arr[y][x];
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        int gab = abs(arr[y][x] - arr[ny][nx]);
        if (gab >= l && gab <= r) dfs(ny, nx);
    }
}

int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (true)
    {
        bool is_changed = false;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    people = 0;
                    opened_yx.clear();
                    dfs(i, j);
                    if (opened_yx.size() == 1) continue;
                    is_changed = true;
                    int average = people / opened_yx.size();
                    for (pair<int, int> yx : opened_yx)
                    {
                        arr[yx.first][yx.second] = average;
                    }
                }
            }
        }
        if (!is_changed) break;
        ret++;
    }
    cout << ret << "\n";
    return 0;
}