#include <bits/stdc++.h>
using namespace std;

/*
19942 다이어트
https://www.acmicpc.net/problem/19942

브루트포스, 조합 (비트 이용)
사전 순 배열 << 이거때문에 계속 헷갈려서 몇번 틀림
*/

int n, mp, mf, ms, mv, mcost = 1010101010;
struct A
{
    int _p, _f, _s, _v, _cost;
} a[16];
map<int, vector<vector<int>>> ret_v;
// "사전 순 배열" 때문에 sort 쓰려고 이렇게 함

int main()
{
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]._p >> a[i]._f >> a[i]._s >> a[i]._v >> a[i]._cost;
    }
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> tmp;
        int sp = 0, sf = 0, ss = 0, sv = 0, scost = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {   
                tmp.push_back(j + 1);
                sp += a[j]._p;
                sf += a[j]._f;
                ss += a[j]._s;
                sv += a[j]._v;
                scost += a[j]._cost;
            }
        }
        if (sp < mp || sf < mf || ss < ms || sv < mv) continue;
        if (scost <= mcost)
        {
            mcost = scost;
            ret_v[scost].push_back(tmp);
        }
    }
    if (mcost == 1010101010)
    {
        cout << "-1\n";
    }
    else
    {
        cout << mcost << "\n";
        sort(ret_v[mcost].begin(), ret_v[mcost].end());
        for (int i : ret_v[mcost][0]) cout << i << " ";
    }

    return 0;
}