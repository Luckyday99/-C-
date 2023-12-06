#include <bits/stdc++.h>
using namespace std;

/*
17471 게리맨더링
https://www.acmicpc.net/problem/17471

dfs, 조합 -> 비트마스킹 사용
*/

using pii = pair<int, int>;
const int INF = 1010101010;
int n, m, ret = INF, arr[12], visited[12], cmp[12];
vector<int> adj[12];

pii dfs(int here)
{
    pii ret = {1, arr[here]};
    visited[here] = true;
    for (int there : adj[here])
    {
        if (visited[there]) continue;
        if (cmp[there] != cmp[here]) continue;
        pii tmp = dfs(there);
        /* 여기서 그냥
        ret.first += dfs(there).first;
        ret.second += dfs(there).second;
        이렇게 했다가 틀림
        */
        ret.first += tmp.first;
        ret.second += tmp.second;
    }
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            adj[i].push_back(tmp);
        }
    }
    for (int i = 1; i < (1 << n) - 1; i++)
    {
        memset(cmp, 0, sizeof(cmp));
        memset(visited, 0, sizeof(visited));
        int idx0 = -1, idx1 = -1;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j)) 
            {
                idx1 = j + 1;
                cmp[j + 1] = 1;
            }
            else idx0 = j + 1;
        }
        pii ret0 = dfs(idx0);
        pii ret1 = dfs(idx1);
        if (ret0.first + ret1.first == n)
            ret = min(ret, abs(ret0.second - ret1.second));
    }
    if (ret == INF) ret = -1;
    cout << ret << "\n";

    return 0;
}