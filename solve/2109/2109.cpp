#include <bits/stdc++.h>
using namespace std;

/*
2109 순회강연
https://www.acmicpc.net/problem/2109

그리디(sort + pq)
*/

int n, p, d, ret;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        pq.push(v[i].second);
        if (pq.size() > v[i].first) pq.pop();
    }
    while (pq.size())
    {
        ret += pq.top();
        pq.pop();
    }
    cout << ret << '\n';

    return 0;
}