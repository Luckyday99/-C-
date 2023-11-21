#include <bits/stdc++.h>
using namespace std;

/*
1159 농구 경기
https://www.acmicpc.net/problem/1159
*/

int main()
{
    int n, name[26] = {0,};
    // 26 대신에 'z' - 'a'로 썼다가 틀렸음 (+1 안함)
    string input, ret;

    cin >> n;
    for (int i = 0; i < n; i++)
    {   
        cin >> input;
        name[input[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (name[i] >= 5) ret += i + 'a';
    if (ret.size()) cout << ret;
    else cout << "PREDAJA";
    cout << "\n";

    return 0;
}