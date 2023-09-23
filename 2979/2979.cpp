#include <bits/stdc++.h>
using namespace std;

/*
2979 트럭 주차
https://www.acmicpc.net/problem/2979
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d, e, time[100] = {0,}, pay = 0;
    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++)
    {
        cin >> d >> e;
        for (int i = d; i < e; i++) time[i]++;
    }
    for (int i = 0; i < 100; i++)
    {
        switch (time[i])
        {
        case 0:
            break;
        case 1:
            pay += a;
            break;
        case 2:
            pay += b * 2;
            break;
        case 3:
            pay += c * 3;
            break;
        }
    }
    cout << pay;

    return 0;
}