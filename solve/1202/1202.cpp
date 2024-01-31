#include <bits/stdc++.h>
using namespace std;

/*
1202 보석 도둑
https://www.acmicpc.net/problem/1202

정렬 => 우선순위 큐(priority queue), 그리디
*/

int n, k;
long long ret;

int main()
{
    cin >> n >> k;
    vector<pair<int, int>> v_cry(n);
    vector<int> v_bag(k);
    for (int i = 0; i < n; i++)
    {
        cin >> v_cry[i].first >> v_cry[i].second;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> v_bag[i];
    }
    sort(v_cry.begin(), v_cry.end());
    sort(v_bag.begin(), v_bag.end());
    priority_queue<int> pq;

    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && v_cry[idx].first <= v_bag[i])
        {
            pq.push(v_cry[idx].second);
            idx++;
        }
        if (pq.size())
        {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << "\n";

    return 0;
}