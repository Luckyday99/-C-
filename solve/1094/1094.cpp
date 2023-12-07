#include <bits/stdc++.h>
using namespace std;

/*
1094 막대기
https://www.acmicpc.net/problem/1094

비트마스킹
64인거 보고 바로 비트마스킹인걸 눈치챘어야 했는데 좀 늦어서 돌아왔다.
근데 풀고 나서 보니까 그냥 (1 << i) & sum 해서 1 개수만 찾으면 되는 문제 같아서 해볼 예정 => 맞았음 (2번 풀이)
*/

int X, cnt = 1, sum = 63, bit = 64;

int main()
{
    cin >> X;
    X -= 1;
    while (true)
    {
        if (sum == X) break;
        bit = bit >> 1;
        if ((sum & ~bit) >= X) sum &= ~bit;
        else cnt++;
    }
    cout << cnt;

    return 0;
}