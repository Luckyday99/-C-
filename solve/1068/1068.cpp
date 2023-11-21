#include <bits/stdc++.h>
using namespace std;

/*
1068 트리
https://www.acmicpc.net/problem/1068

dfs, 트리
*/

int n, inp, root, rmv;
vector<int> v[54];

int dfs(int a)
{
    int cnt = 0;
    int child = 0;
    for (int i : v[a])
    {
        if (i == rmv) continue;
        cnt += dfs(i);
        child++;
    }
    if (!child) return 1;
    return cnt;
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        if (inp == -1) root = i;
        else v[inp].push_back(i);
    }
    cin >> rmv;
    if (rmv == root)
    {
        cout << "0\n";
        return 0;
    }
    cout << dfs(root) << "\n";
    return 0;
}
