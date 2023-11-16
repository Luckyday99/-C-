#include <bits/stdc++.h>
using namespace std;

/*
너비 우선 탐색 Breadth First Search

같은 깊이의 모든 정점을 우선 탐색
=> 같은 가중치를 가진 그래프의 최단거리 알고리즘
    (가중치가 다를 떄는 다익스트라, 벨만포드 알고리즘 등)

vs DFS
메모리를 더 사용, 코드가 좀 더 김
시간복잡도 동일
가중치 같은 그래프 내 최단거리 구할 수 있음

BFS(G, u)
    u.visited = true
    q.push(u)
    while (q.size())
        u = q.front()
        q.pop()
        for v in G.adj[u]
            if v.visited == false
                v.visited = true
                q.push(v)

BFS_2(G, u) -> 최단거리 배열 생성
    u.visited = 1
    q.push(u)
    while (q.size())
        u = q.front()
        q.pop()
        for v in G.adj[u]
            if v.visited == false
                v.visited = u.visited + 1 // visited 횟수 기록하여 최단 거리 계산
                q.push(v)
*/

vector<int> adj[100];
int visited[100];
int nodelist[] = {10, 12, 14, 16, 18, 20, 22, 24};

void BFS(int here)
{
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while (q.size())
    {
        int here = q.front();
        q.pop();
        for (int there : adj[here])
        {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}

int main()
{
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);

    BFS(10);

    for (int i : nodelist)
        cout << i << " : " << visited[i] << "\n";
    cout << "10 >> 24 최단거리 : " << visited[24] - 1 << "\n";

    return 0;
}