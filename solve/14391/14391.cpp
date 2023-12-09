#include <bits/stdc++.h>
using namespace std;

/*
14391 종이 조각
https://www.acmicpc.net/problem/14391

비트마스킹, dfs
다른 사람들 정답 보니까 dfs 안쓰고 푸는게 경우가 더 빨랐다.
경우가 두개밖에 없어서 dfs 안쓰고 그냥 if 분기로 처리해도 별로 안복잡하고 더 빨랐던듯
*/

int n, m, visited[5][5], bits, ret;
char arr[5][5];

string dfs(int y, int x, int prev_bit)
{
    string s = "";
    s += arr[y][x];
    visited[y][x] = true;
    int ny = y, nx = x;
    if (prev_bit == 0) nx++;
    else ny++;
    if (ny >= 0 && nx >= 0 && ny < n && nx < m && !(bits & (1 << (ny * m + nx))) == !prev_bit)
    // ! : 불리언(true/false) 으로만 사용
    {
        s += dfs(ny, nx, prev_bit);
    }
    return s;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (bits = 0; bits < (1 << n * m); bits++)
    {
        memset(visited, 0, sizeof(visited));
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j])
                {
                    sum += stoi(dfs(i, j, bits & (1 << (i * m + j))));
                }
            }
        }
        ret = max(ret, sum);
    }
    cout << ret << "\n";

    return 0;
}