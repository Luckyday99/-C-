#include <bits/stdc++.h>
using namespace std;

/*
인접 행렬 vs 인접 리스트

공간복잡도
O(V^2) / O(V + E)

시간복잡도

한개 찾을 때
O(1) / O(V)

다 찾을 때
O(V^2) / O(V+E)

->  그래프가 희소할 때 (sparse) : 인접 리스트
    그래프가 조밀할 때 (dense)  : 인접 행렬

    코딩테스트 문제 풀때는 보통 인접리스트 / 문제에서 인접행렬로 주어지면 행렬
*/

const int V = 10;
vector<int> adj[V]; 
int visited[V];

void go(int idx)
{
    cout << idx <<"\n";
    visited[idx] = 1;

    for (int i : adj[idx]) {
        if (visited[i])
        {   
            cout << i << " is already visited.\n";
            continue;
        }
        cout << idx << " >> " << i << "\n";
        go(i);
    } 
    return;
}

int main()
{
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3); 
    adj[3].push_back(1);

    adj[3].push_back(4); 
    adj[4].push_back(3);

    adj[5].push_back(6);

    for (int i = 0; i < V; i++)
	{
        if (adj[i].size() && visited[i] == 0) go(i);
    } 
}