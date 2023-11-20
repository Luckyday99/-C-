#include <bits/stdc++.h>
using namespace std;

/*
2589 보물섬
https://www.acmicpc.net/problem/2589

bfs, 완전탐색
*/

int n, m, visited[54][54], maxDist;
string inp[54];
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

void bfs(int y, int x)
{
    visited[y][x] = 1;
	queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    while (q.size())
    {
		pair<int, int> here = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;
            if (inp[ny][nx] == 'W') continue;
            q.push(make_pair(ny, nx));
            visited[ny][nx] = visited[here.first][here.second] + 1;
            maxDist = max(maxDist, visited[ny][nx]);
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (inp[i][j] == 'L')
            {
                memset(visited, 0, sizeof(visited));
                bfs(i, j);
            }
        }
    }
    cout << maxDist - 1 << "\n";

    return 0;
}
