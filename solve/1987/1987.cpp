#include <bits/stdc++.h>
using namespace std;

/*
1987 알파벳
https://www.acmicpc.net/problem/1987

dfs
*/

int r, c, ret, visited[24][24];
char arr[24][24];
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
string used;

bool isOOB(int ny, int nx)
{
    return (ny < 0 || nx < 0 || ny >= r || nx >= c);
}

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isOOB(ny, nx)) continue;
        if (visited[ny][nx]) continue;
        if (used.find(arr[ny][nx]) != string::npos) continue;
        used += arr[ny][nx];
        visited[ny][nx] = visited[y][x] + 1;
        dfs(ny, nx);
        used.pop_back();
        visited[ny][nx] = false;
    }
    ret = max(ret, visited[y][x]);
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    visited[0][0] = true;
    used += arr[0][0];
    dfs(0, 0);
    cout << ret << "\n";

    return 0;
}