#include <bits/stdc++.h>
using namespace std;

/*
14502 연구소
https://www.acmicpc.net/problem/14502

dfs

벽 3개니까 각 지점마다 이어지는 노드 개수, 좌표 저장해놓고 1개 이어진 곳 + 2개 이어진 곳 / 3개 이어진 곳
벽으로 막은 뒤에 빈 곳 넓이 구하려 했었는데 하다가 너무 빡세져서 힌트 봄

그냥 벽 3개로 다 막히는 곳 찾는 것 보다 빈 곳 전체에 랜덤으로 벽 3개 세우고 dfs 한번씩 돌려보는게
구현하기 훨씬 쉬웠음
괜히 어렵게 풀지 말고 좀 쉽게 구현할 생각부터 하자..
*/

int n, m, arr[10][10], visited[10][10], max_size;
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
vector<pair<int, int>> virus_list, empty_list;

void dfs(int y, int x)
{
    if (visited[y][x]) return;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (arr[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
}

int calcSize()
{
    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    for (pair<int, int> v : virus_list)
    {
        dfs(v.first, v.second);
    }
    for (pair<int, int> e : empty_list)
    {
        if (!visited[e.first][e.second]) cnt++;
    }
    return cnt - 3;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0) empty_list.push_back(make_pair(i, j));
            if (arr[i][j] == 2) virus_list.push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < empty_list.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < j; k++)
            {
                arr[empty_list[i].first][empty_list[i].second] = 1;
                arr[empty_list[j].first][empty_list[j].second] = 1;
                arr[empty_list[k].first][empty_list[k].second] = 1;
                max_size = max(max_size, calcSize());
                arr[empty_list[i].first][empty_list[i].second] = 0;
                arr[empty_list[j].first][empty_list[j].second] = 0;
                arr[empty_list[k].first][empty_list[k].second] = 0;
            }
        }
    }
    cout << max_size << "\n";

    return 0;
}