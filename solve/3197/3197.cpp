#include <bits/stdc++.h>
using namespace std;

/*
3197 백조의 호수
https://www.acmicpc.net/problem/3197

bfs
1. 백조가 다른 백조한테 닿을 수 있는지 판단 -> bool swan() : bfs
    오답 1 http://boj.kr/5a31400e6a0e4bea85a7f0082562729d
    => 1번을 dfs로 하니까 시간 초과
2. 얼음 녹이기 -> void water() : bfs
3. 반복
*/

using pii = pair<int, int>;

int r, c, visited_water[1504][1504], visited_swan[1504][1504], cnt, swany, swanx;
char arr[1504][1504];
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
queue<pii> waterQ, water_tmpQ, swanQ, swan_tmpQ;

bool isOOB(int ny, int nx)
{
    return (ny < 0 || nx < 0 || ny >= r || nx >= c);
}

void init()
{
    water_tmpQ = waterQ;
    waterQ = queue<pii>();
    swan_tmpQ = swanQ;
    swanQ = queue<pii>();
}

void water()
{
    while (water_tmpQ.size())
    {
        int y = water_tmpQ.front().first;
        int x = water_tmpQ.front().second;
        water_tmpQ.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (isOOB(ny, nx)) continue;
            if (visited_water[ny][nx]) continue;
            visited_water[ny][nx] = visited_water[y][x] + 1;
            if (arr[ny][nx] == '.')
            {
                water_tmpQ.push({ny, nx});
            }
            else if (arr[ny][nx] == 'X')
            {
                waterQ.push({ny, nx});
                arr[ny][nx] = '.';
            }
        }
    }
}

bool swan()
{
    while (swan_tmpQ.size())
    {
        int y = swan_tmpQ.front().first;
        int x = swan_tmpQ.front().second;
        swan_tmpQ.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (isOOB(ny, nx)) continue;
            if (visited_swan[ny][nx]) continue;
            visited_swan[ny][nx] = true;
            if (arr[ny][nx] == '.') swan_tmpQ.push({ny, nx});
            else if (arr[ny][nx] == 'X') swanQ.push({ny, nx});
            else if (arr[ny][nx] == 'L') return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'L')
            {
                swany = i; swanx = j;
                waterQ.push({i, j});
                visited_water[i][j] = 1;
            }
            else if (arr[i][j] == '.')
            {
                waterQ.push({i, j});
                visited_water[i][j] = 1;
            }
        }
    }
    swanQ.push({swany, swanx});
    visited_swan[swany][swanx] = true;
    while (true)
    {
        init();
        if (swan()) break;
        water();
        cnt++;
    }
    cout << cnt << "\n";

    return 0;
}