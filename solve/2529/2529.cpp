#include <bits/stdc++.h>
using namespace std;

/*
2529 부등호
https://www.acmicpc.net/problem/2529

구현
찾아보니 재귀함수, 백트래킹으로 푸는 풀이도 있었음
나는 이게 더 나은 것 같아서 그냥 이걸로 저장
*/

int k;
string s, ret_mx = "9", ret_mn = "0";
vector<int> v;

int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> s[i];
        if (s[i] != s[i - 1]) v.push_back(i);
        ret_mn += i + '1';
        ret_mx += '8' - i;
    }
    v.push_back(k);
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (s[v[i]] == '>') reverse(ret_mn.begin() + v[i], ret_mn.begin() + v[i + 1] + 1);
        else reverse(ret_mx.begin() + v[i], ret_mx.begin() + v[i + 1] + 1);
    }
    cout << ret_mx << "\n" << ret_mn << "\n";

    return 0;
}