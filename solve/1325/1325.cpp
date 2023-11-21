#include <bits/stdc++.h>
using namespace std;

/*
1325 효율적인 해킹
https://www.acmicpc.net/problem/1325

dfs
*/

int n, m, a, b, visited[10004], hacked[10004], max_hacked;
vector<int> trust[10004];

int dfs(int here)
{
    int cnt = 1;
    visited[here] = true;
    for (int there : trust[here])
    {
        if (visited[there]) continue;
        cnt += dfs(there);
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        trust[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        hacked[i] = dfs(i);
        max_hacked = max(max_hacked, hacked[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (hacked[i] == max_hacked) cout << i << " ";
    }

    return 0;
}
