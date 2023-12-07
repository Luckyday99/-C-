#include <bits/stdc++.h>
using namespace std;

/*
1094 막대기
https://www.acmicpc.net/problem/1094

비트마스킹
2번 풀이
그냥 1 개수만 찾으면 되는 간단한 문제..
*/

int X, cnt, sum = 64;

int main()
{
    cin >> X;
    for (int i = 0; i < 7; i++) if (X & (1 << i)) cnt++;
    cout << cnt;
    return 0;
}