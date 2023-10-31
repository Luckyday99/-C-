#include <bits/stdc++.h>
using namespace std;

/*
1620 나는야 포켓몬 마스터 이다솜
https://www.acmicpc.net/problem/1620

검색 잦을 때, 중간 삽입(insert) 있을 때 -> map or set 사용
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    map<string, int> dogam_number;
    vector<string> dogam_name;
    string temp;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        dogam_number[temp] = i;
        dogam_name.push_back(temp);
    }

    for (int i = 0; i < m; i++)
    {   
        cin >> temp;
        if (dogam_number.find(temp) != dogam_number.end()) cout << dogam_number[temp] + 1 << "\n";
        else cout << dogam_name[atoi(temp.c_str()) - 1] << "\n";
    }

    return 0;
}