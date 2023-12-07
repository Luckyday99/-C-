#include <bits/stdc++.h>
using namespace std;

/*
2234 성곽
https://www.acmicpc.net/problem/2234

비트마스킹, dfs
dfs에서 방 크기, 접해있는 다른 방 정보 (비트마스킹)으로 저장
*/

using pii = pair<int, int>;
int n, m, arr[52][52], visited[52][52], ret1, ret2, ret3;
const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };
vector<pii> v;

pii dfs(int y, int x, int counted_bit)
{
    int size = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx])
        {
            if (visited[ny][nx] != visited[y][x]) counted_bit |= (1 << visited[ny][nx] - 1);
            continue;
        }
        if (arr[y][x] & (1 << i)) continue;
        visited[ny][nx] = visited[y][x];
        pii tmp = dfs(ny, nx, counted_bit);
        size += tmp.first;
        counted_bit = tmp.second;
    }
    return {size, counted_bit};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                ret1++;
                visited[i][j] = ret1;
                v.push_back(dfs(i, j, 0));
                ret2 = max(ret2, v[ret1 - 1].first);
                for (int k = 0; k < ret1; k++)
                {
                    if (v[ret1 - 1].second & (1 << k)) ret3 = max(ret3, v[ret1 - 1].first + v[k].first);
                }
            }
        }
    }
    cout << ret1 << "\n" << ret2 << "\n" << ret3 << "\n";

    return 0;
}