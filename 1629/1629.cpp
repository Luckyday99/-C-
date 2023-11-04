#include <bits/stdc++.h>
using namespace std;

/*
1629 °ö¼À
https://www.acmicpc.net/problem/1629

3 ^ 8 = 3 ^ 2 ^ 2 ^ 2
3 ^ 9 = 3 ^ (8 + 1) = 3 ^ (2 ^ 2 ^ 2 + 1)
3 ^ 10 = 3 ^ 2 ^ 5 = 3 ^ 2 ^ (2 ^ 2 + 1) 
*/

using ll = long long;
ll a, b, c;

ll sol(ll _a, ll _b)
{
	if (_a == 1 || _b == 1)	return _a % c;
		
	ll ret = sol(_a, _b / 2);
	ret = (ret * ret) % c;
	if (_b % 2) ret = (ret * _a) % c;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b >> c;
	cout << sol(a, b) << "\n";
		
	return 0;
}
