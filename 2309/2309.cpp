#include <bits/stdc++.h>
using namespace std;

/*
2309 일곱 난쟁이 https://www.acmicpc.net/problem/2309
아홉 명의 난쟁이 중 키의 합이 100인 일곱 난쟁이를 찾기
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int height[9];
    for (int i = 0; i < 9; i++) cin >> height[i];
    sort(height, height+9);

    do
    {
        int sum = 0;
        for (int i = 0; i < 7; i++) sum += height[i];

        if (sum == 100) break;
    }
    while (next_permutation(height, height+9));

    for (int i = 0; i < 7; i++) cout << height[i] << '\n';
    return 0;
}