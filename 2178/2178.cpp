#include <bits/stdc++.h>
using namespace std;

/*
2178 미로 탐색
https://www.acmicpc.net/problem/2178

가중치 동일, 최단거리 -> BFS
*/

enum {
    E   = 0,
    N   = 1,
    W   = 2,
    S   = 3,

    END = 4
};

const int MAX_N = 104;
int n, m, maze[MAX_N][MAX_N], visited[MAX_N][MAX_N], x , y;
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &maze[i][j]);
        }
    }
    queue<pair<int, int> > q;
    visited[0][0] = 1;
    q.push(make_pair(0, 0));
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = E; i  < END; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (maze[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
    printf("%d", visited[n-1][m-1]);

    return 0;
}