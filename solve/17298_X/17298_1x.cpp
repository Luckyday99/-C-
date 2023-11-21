#include <bits/stdc++.h>
using namespace std;

/*
17298 오큰수
https://www.acmicpc.net/problem/17298

시간초과
범위가 100만 -> 시간복잡도 최대 1000000000000
시간복잡도 1억 넘어가면 다른 방법 고민해야함...
반대로 시간복잡도 1억, 1000만 밑이면 그냥 이렇게 하는게 정답일 확률 높음
*/

int a, arr[1000004];

int NGE(int inp)
{
    for (int i = inp; i <= a; i++)
    {
        if (arr[inp] < arr[i]) return arr[i];
    }
    return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> a;
	for (int i = 1; i <= a; i++)
	{
		cin >> arr[i];
	}
    for (int i = 1; i <= a; i++)
    {
        cout << NGE(i) << " ";
    }

    return 0;
}
