#include <bits/stdc++.h>
using namespace std;

/*
1285 동전 뒤집기
https://www.acmicpc.net/problem/1285

비트마스킹, 브루트포스

처음에 비트마스킹 안하고 풀어보려다 시간 초과
=> 행, 열 하나씩 뒤집어보면서 검사 => 시간초과(O(2^N^2))
=> 행 뒤집고 열 검사 => O(2 * N * N^2)
*/

int n, arr[24], ret = 1010101010;
string s;

void go(int y)
{
    // 한 열씩 넘겨가면서 결과 계산
    if (y == n + 1)
    {
        int sum = 0;
        for (int i = 1; i <= (1 << (n - 1)); i *= 2)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++) if (arr[j] & i) cnt++;
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }
    // 먼저 한 행씩 뒤집고
    go(y + 1);
    arr[y] = ~arr[y]; // 한번에 한 행 다 뒤집기 가능
    go(y + 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int t = 1;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'T') arr[i] |= t;
            t *= 2;
        }
    }
    go(1);
    cout << ret << "\n";

    return 0;
}