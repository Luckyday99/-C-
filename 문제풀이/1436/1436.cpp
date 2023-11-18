#include <bits/stdc++.h>
using namespace std;

/*
1436 영화감독 숲
https://www.acmicpc.net/problem/1436

3자리 : a1 = 1 개
4자리 : a2 = 8 * a1 + 10 ^ 1 = 18 개
5자리 : a3 = 8 * a2 + 10 ^ 2 개
...
int function (int digit)
{
    if (digit < 3) return 0;
    if (digit == 3) return 1;
    return 8 * function(digit - 1) + pow (10, digit - 3);
}
int findEvil(int i)
{
    for (int d = 3; function(d) > i; d++)
    {}
}
...?
=============
괜히 어렵게 풀지 말고 걍 구현하고 계산은 컴퓨터에게 맡길것...
*/

int n;

int main()
{
    cin >> n;
    int i = 666;
    while (n - 1)
    {
        i++;
        if (to_string(i).find("666") != string::npos) n--;
    }
    cout << i << "\n";

    return 0;
}
