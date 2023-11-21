#include <bits/stdc++.h>
using namespace std;

/*
15686 치킨 배달
https://www.acmicpc.net/problem/15686

완전탐색, 조합
*/

int n, m, arr[54][54], ret = INT_MAX;
vector<pair<int, int>> chicken_list, home_list;
vector<vector<int>> comb_ret;

void comb(int start, vector<int> v)
{
    if (v.size() == m)
    {
        comb_ret.push_back(v);
        return;
    }
    for (int i = start + 1; i < chicken_list.size(); i++)
    {
        v.push_back(i);
        comb(i, v);
        v.pop_back();
    }
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1) home_list.push_back(make_pair(i, j));
            if (arr[i][j] == 2) chicken_list.push_back(make_pair(i, j));
        }
    }
    vector<int> v;
    comb(-1, v);
    for (vector<int> cList : comb_ret)
    {
        int cDist_sum = 0;
        for (pair<int, int> home : home_list)
        {
            int cDist_home = INT_MAX;
            for (int idx : cList)
            {
                cDist_home = min(abs(home.first - chicken_list[idx].first) + abs(home.second - chicken_list[idx].second), cDist_home);
            }
            cDist_sum += cDist_home;
        }
        ret = min(cDist_sum, ret);
    }
    cout << ret << "\n";

    return 0;
}
