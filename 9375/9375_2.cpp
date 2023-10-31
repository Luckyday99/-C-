#include <bits/stdc++.h>
using namespace std;

/*
9375 패션왕 신해빈
https://www.acmicpc.net/problem/9375

map<string, int> 사용
굳이 옷 이름까지 저장할 필요가 없었음
*/

int c, n;
string tmp, where;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> c;
    while(c--)
    {   
        map<string, int> mp;
        int ret = 1;
        cin >> n;
        for (int j = 0; j < n; j++) 
        {
            cin >> tmp >> where;
            mp[where]++;
        }
        for (auto c : mp)
            ret *= (c.second + 1);
        cout << ret - 1 << "\n";
    }

    return 0;
}