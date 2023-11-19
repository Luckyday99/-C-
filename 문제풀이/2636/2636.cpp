#include <bits/stdc++.h>
using namespace std;

/*
2636 치즈
https://www.acmicpc.net/problem/2636

dfs 구현
*/

int n, m, arr[104][104], visited[104][104], cnt;
vector<int> cnt_list;
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

void go(int y, int x)
{
    if (visited[y][x]) return;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (arr[ny][nx] == 0) go(ny, nx);
        else if (visited[y][x] == 1)
        {
            arr[ny][nx] = 0;
            visited[ny][nx] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (true)
    {
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1) cnt++;
            }
        }
        if (!cnt) break;
        cnt_list.push_back(cnt);
        go(0, 0);
    }
    cout << cnt_list.size() << "\n";
    cout << cnt_list[cnt_list.size() - 1] << "\n";

    return 0;
}
