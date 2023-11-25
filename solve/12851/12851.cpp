#include <bits/stdc++.h>
using namespace std;

int n, k, cnt[200004], visited[200004];

/*
12851 숨바꼭질 2
https://www.acmicpc.net/problem/12851

bfs

왜 계속 안되나 했는데 move 함수 이용해서 1초 후 위치를 정했는데 std::move 함수가 이미 있었다...
왜 여기서 실행할 때는 아무런 문제 없이 돌아갔을까...
*/
/*
int move(int num, int i)
{
    if (i == 0) return num - 1;
    if (i == 1) return num + 1;
    if (i == 2) return num * 2;
}
*/

void bfs(int arr)
{
    queue<int> q;
    q.push(arr);
    while(q.size())
    {
        int x = q.front();
        q.pop();
        // for (int i = 0; i < 3; i++)
        for (int nx : {x - 1, x + 1, x * 2})
        {
            // int nx = move(x, i);
            if (nx < 0 || nx > 200000) continue;
            if (!visited[nx])
            {
                q.push(nx);
                visited[nx] = visited[x] + 1;
                cnt[nx] += cnt[x];
            }
            else if (visited[nx] == visited[x] + 1)
            {
                cnt[nx] += cnt[x];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    visited[n] = 1;
    cnt[n] = 1;
    bfs(n);
    cout << visited[k] - 1 << "\n" << cnt[k] << "\n";

    return 0;
}