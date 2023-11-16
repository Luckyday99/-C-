#include <bits/stdc++.h>
using namespace std;

/*
누적 합(prefix sum)


배열에서 n1 ~ n2 번째의 합을 구해라

psum[n1] - psum[n2 - 1]
-> 0 ~ n 번째까지의 합들을 모두 구해놓고 뺄셈 한번으로 계산
정적 배열에서 사용
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int inp[100004], a, b, psum[100004], n, m;

    cin >> n >> m;
    cin >> inp[0];
    psum[0] = inp[0];

    for (int i = 1; i < n; i++)
    {
        cin >> inp[i];
        psum[i] = psum[i-1] + inp[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cout << psum[b-1] - psum[a-2] << '\n';
    }

    return 0;
}