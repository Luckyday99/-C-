#include <bits/stdc++.h>
using namespace std;

/*
2468 안전 영역
https://www.acmicpc.net/problem/2468

완전 탐색 -> dfs, 브루트포스
*/

const int MAX_N = 104;
int n, a[MAX_N][MAX_N], visited[MAX_N][MAX_N], ret = 1;

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

void dfs(int y, int x, int h)
{
	visited[y][x] = true;
	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx] == true) continue;
		if (a[ny][nx] > h) dfs(ny, nx, h);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	
    for (int h = 1; h < 101; h++)
    {
    	int cnt = 0;
    	memset(visited, 0, sizeof(visited));
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			if (a[i][j] > h && visited[i][j] == false)
    			{
    				dfs(i, j , h);
    				cnt ++;
				}
			}
		}
		ret = max(ret, cnt);
	}
	cout << ret << "\n";
    
    return 0;
}
