#include <bits/stdc++.h>
using namespace std;

/*
2583 영역 구하기
https://www.acmicpc.net/problem/2583

넓이 구하길래 bfs인줄 알았으나 dfs
*/

const int MAX_N = 104;
int m, n, k, ly, lx, ry, rx, cnt, ret[MAX_N], arr[MAX_N][MAX_N], visited[MAX_N][MAX_N];

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

void dfs(int y, int x)
{
	ret[cnt]++;
	visited[y][x] = true;
	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx] == true) continue;
		if (arr[ny][nx] == false)
		{
			dfs(ny, nx);
		}
	}
}

int main()
{
	cin >> m >> n >> k;
	while (k--)
	{
		cin >> lx >> ly >> rx >> ry;
		for (int i = lx; i < rx; i++)
		{
			for (int j = ly; j < ry; j++)
			{
				arr[i][j]++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == false && visited[i][j] == false)
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	sort(ret, ret + cnt);
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
		cout << ret[i] << " ";
	cout << "\n";
	
	return 0;
}
