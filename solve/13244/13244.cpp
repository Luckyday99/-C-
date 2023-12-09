#include <bits/stdc++.h>
using namespace std;

/*
13244 Tree
https://www.acmicpc.net/problem/13244

dfs, tree
오답1 http://boj.kr/2e8b8eb7d11d427f885b2f16a1fb0763
-> m 크기 생각 안하고 연결리스트를 비트마스킹으로 만들어서 틀림 (노드 최대 1m개, int 범위 벗어나서 오버플로우)
*/

int t, n, m, a, b, visited[1004];
vector<int> adj[1004];

int dfs(int here)
{
    visited[here] = true;
    int cnt = 1;
    for (int i : adj[here])
    {
        if (!visited[i]) cnt += dfs(i);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> m;
        memset(visited, 0, sizeof(visited));
        for (vector<int> v : adj) v.clear();
        for (int j = 0; j < m; j++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (n - 1 == m && dfs(1) == n) cout << "tree\n";
        else cout << "graph" << "\n";
    }

    return 0;
}