#include <bits/stdc++.h>
using namespace std;

/*
14620 꽃길
https://www.acmicpc.net/problem/14620

구현, 백트래킹
*/

int n, arr[14][14], flowered[14][14], cost, ret = 1010101010;
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

bool flower(int y, int x)
{
    if (flowered[y][x]) return false;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (flowered[ny][nx]) return false;
    }
    return true;
}

void SetFlower(int y, int x)
{
    cost += arr[y][x];
    flowered[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        flowered[ny][nx] = true;
        cost += arr[ny][nx];
    }
}

void DeleteFlower(int y, int x)
{
    cost -= arr[y][x];
    flowered[y][x] = false;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        flowered[ny][nx] = false;
        cost -= arr[ny][nx];
    }
}

void go(int cnt)
{
    if (cnt == 3)
    {
        ret = min(ret, cost);
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (flower(i, j))
            {
                SetFlower(i, j);
                go(cnt + 1);
                DeleteFlower(i, j);
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    go(0);
    cout << ret << "\n";

    return 0;
}