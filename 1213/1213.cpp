#include <bits/stdc++.h>
using namespace std;

/*
1213 펠린드롬 만들기
https://www.acmicpc.net/problem/1213
*/

string str, ret;
char cnt[26], mid;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str;
    for (char c : str)
        cnt[c - 'A']++;

    int odd = 0;
    for (int i = 25; i >= 0; i--)
    {
        if (cnt[i]) // 0아닐때
        {
            if (cnt[i] & 1) // 홀수면
            {
                mid = static_cast<char>(i + 'A');
                odd++;
                cnt[i]--;
            }
            if (odd > 1) break; // 홀수 2개이상 -> Sorry
            for (int j = cnt[i]; j > 0; j -= 2) // 짝수
            {
                ret += static_cast<char>(i + 'A'); // ZZX
                ret = static_cast<char>(i + 'A') + ret; // XZZX
            }
        }
    }
    if (mid) ret.insert(ret.begin() + ret.size()/2, mid);
    if (odd > 1) cout << "I'm Sorry Hansoo\n";
    else cout << ret << "\n";

    return 0;
}