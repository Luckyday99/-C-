#include <bits/stdc++.h>
using namespace std;

/*
14497 주난의 난
https://www.acmicpc.net/problem/14497

bfs, flood fill
*/

#define y1 aaa

int n, m, x1, y1, x2, y2, visited[304][304];
char arr[304][304];
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

void solve(int y, int x)
{
    queue<pair<int, int>> q, tmp;
    visited[y][x] = 1;
    q.push(make_pair(y, x));
    for (int cnt = 1; q.size(); cnt++)
    {
        tmp = q;
        q = queue<pair<int, int>> ();
        while(tmp.size())
        {
            int y = tmp.front().first;
            int x = tmp.front().second;
            tmp.pop();
            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
                if (arr[ny][nx] == '0')
                {
                    visited[ny][nx] = cnt;
                    tmp.push(make_pair(ny, nx));
                }
                else if (arr[ny][nx] == '1')
                {
                    visited[ny][nx] = cnt;
                    q.push(make_pair(ny, nx));
                }
                else if (arr[ny][nx] == '#')
                {
                    cout << cnt << "\n";
                    return;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    if (x1 == x2 && y1 == y2)
    {
        cout << "0\n";
    }
    x1--; y1--; x2--; y2--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    solve(y1, x1);

    return 0;
}