#include <bits/stdc++.h>
using namespace std;

/*
13913 숨바꼭질 4
https://www.acmicpc.net/problem/13913

bfs 12851이랑 거의 동일한 문제
*/

int n, k, visited[200004], prevNode[200004], ret;
vector<int> v;

void bfs()
{
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (x == k)
        {
            ret = visited[x];
            break;
        }
        for (int nx : {x - 1, x + 1, x * 2})
        {
            if (nx < 0 || nx >= 200004) continue;
            // nx > 200004 해서 한번 틀렸음
            // ->   배열들 최대값 넘겨서 오버플로우인건 알겠는데
            //      bfs인데 200004 까지 가는 경우의 수가 있나?
            if (visited[nx]) continue;
            visited[nx] = visited[x] + 1;
            prevNode[nx] = x;
            q.push(nx);
        }
    }
    for (int i = k; i != n; i = prevNode[i]) v.push_back(i);
    v.push_back(n);
    reverse(v.begin(), v.end());
}

int main()
{
    cin >> n >> k;
    visited[n] = 1;
    bfs();
    cout << ret - 1 << "\n";
    for (int i : v) cout << i << " ";

    return 0;
}