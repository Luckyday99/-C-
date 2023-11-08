#include <bits/stdc++.h>
using namespace std;

/*
깊이우선탐색 Depth First Search

vs BFS
메모리를 덜 씀, 코드가 좀 더 짧음
시간복잡도 동일
완전 탐색할 때 많이 사용

DFS(u, adj)
    u.visited = true;
    for v in adj[u]
        if v.visited == false
            DFS(v, adj)
*/

const int n = 6;
vector<int> adj[n];
int visited[n];

void DFS_1(int here) // visited를 먼저 확인하고 visited[there] == false면 DFS 호출
{
    visited[here] = true;
    cout << "START : " << here << "\n";
    for (int there : adj[here])
    {
        if (visited[there]) 
        {   
            cout << there << " is already visited.\n";
            continue;
        }
        cout << "go to " << there << "\n";
        DFS_1(there);
    }
    cout << "END : " << here << "\n";
}

void DFS_2(int here) // 일단 DFS 호출하고, visited 확인해서 false면 함수 종료
{
    cout << "START : " << here << "\n";
    if (visited[here]) 
    {   
        cout << here << " is already visited.\n";
        cout << "END : " << here << "\n";
        return;
    }
    visited[here] = 1;
    for (int there : adj[here])
    {
        cout << "go to " << there << "\n";
        DFS_2(there);
    }
}

int main()
{
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(4);
    adj[2].push_back(5);
    DFS_1(1);
    cout << "\n=========\n\n";
    memset(visited, 0, n);
    DFS_2(1);

    return 0;
}