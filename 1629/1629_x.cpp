#include <bits/stdc++.h>
using namespace std;

/*
1629 °ö¼À
https://www.acmicpc.net/problem/1629

3 ^ 8 = 3 ^ 2 ^ 2 ^ 2
3 ^ 9 = 3 ^ 3 ^ 3.
½Ã°£ÃÊ°ú ..?
*/

using ll = long long;

ll a, b, c;
ll sol()
{
	if (a == 1 || b == 1) return a % c;
	for (int i = 2; i <= b; i++)
	{
		if (b % i == 0)
		{
			ll tmp = a;
			for (int j = 1; j < i; j++) a = (a * tmp) % c;
			b /= i;
				
			return sol();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b >> c;
	cout << sol() << "\n";
		
	return 0;
}
