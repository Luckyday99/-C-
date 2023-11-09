#include <bits/stdc++.h>
using namespace std;

/*
1012 유기농 배추
https://www.acmicpc.net/problem/1012

인접 행렬 + 완전 탐색 -> DFS
*/

enum{
    EAST    = 0,
    NORTH   = 1,
    WEST    = 2,
    SOUTH   = 3,
    
    END     = 4
};

const int MAX_N = 54;
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
int t, m, n, k, x, y;
bool arr[MAX_N][MAX_N], visited[MAX_N][MAX_N];

void go(int x, int y)
{
    visited[x][y] = true;
    for (int dir = EAST; dir < END; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (arr[nx][ny] == false) continue;
        if (visited[nx][ny] == true) continue;
        go(nx, ny);
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k;
        int bug = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        while(k--)
        {
            cin >> x >> y;
            arr[x][y] = true;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == true && visited[i][j] == false)
                {
                    go(i,j);
                    bug++;
                }
            }
        }
        cout << bug << "\n";
    }

    return 0;
}