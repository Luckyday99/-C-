#include <bits/stdc++.h>
using namespace std;

/*
2559 수열
https://www.acmicpc.net/problem/2559
*/

int main()
{
    int n, k, temp, psum[100001] = {0, }, ret = 0x80000000;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }
    for (int i = k; i <= n; i++)
    {
        ret = max(ret, psum[i] - psum[i - k]);
    }
    cout << ret << "\n";

    return 0;
}