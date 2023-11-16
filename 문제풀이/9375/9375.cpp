#include <bits/stdc++.h>
using namespace std;

/*
9375 패션왕 신해빈
https://www.acmicpc.net/problem/9375
*/

int c, n;
string clo, where;
multimap<string, string> mmp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> c;
    for (int i = 0; i < c; i++)
    {   
        int ret = 1;
        cin >> n;
        for (int j = 0; j < n; j++) 
        {
            cin >> clo >> where;
            mmp.insert(make_pair(where, clo));
        }
        auto it = mmp.begin();
        while (it != mmp.end())
        {
            ret *= mmp.count(it->first) + 1;
            mmp.erase(it->first);
            it = mmp.begin();
        }
        cout << ret - 1 << "\n";
    }

    return 0;
}