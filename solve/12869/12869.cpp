#include <bits/stdc++.h>
using namespace std;

/*
12869 뮤탈리스크
https://www.acmicpc.net/problem/12869

bfs
가중치 같을 때, 최단거리 알고리즘
bfs인건 보자마자 알았는데 처음 보는 형태라서 구현할때 많이 헷갈렸음
-> 손으로 직접 그림 그려보고 구현하니까 쉬웠음
*/

struct A
{
    int a, b, c;
};
int n, hp[3], visited[64][64][64];
const int damage[6][3] = {
    { 9, 3, 1 },
    { 9, 1, 3 },
    { 3, 9, 1 },
    { 3, 1, 9 },
    { 1, 3, 9 },
    { 1, 9, 3 }
};

int bfs(int a, int  b, int c)
{
    queue<A> q;
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while (q.size())
    {
        A scv = q.front();
        q.pop();
        if (visited[0][0][0]) break;
        for (int i = 0; i < 6; i++)
        {
            int na = max(0, scv.a - damage[i][0]);
            int nb = max(0, scv.b - damage[i][1]);
            int nc = max(0, scv.c - damage[i][2]);
            if (visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[scv.a][scv.b][scv.c] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0] - 1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> hp[i];
    cout << bfs(hp[0], hp[1], hp[2]) << "\n";

    return 0;
}