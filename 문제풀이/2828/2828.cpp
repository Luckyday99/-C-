#include <bits/stdc++.h>
using namespace std;

/*
2828 사과 담기 게임
https://www.acmicpc.net/problem/2828
*/

int n, m, j, inp, cnt, basket_left, basket_right;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	basket_left = 1;
	basket_right = m;
	cin >> j;
	while (j--)
	{
		cin >> inp;
		if (inp >= basket_left && inp <= basket_right) continue;
		if (inp < basket_left)
		{
			int move = basket_left - inp;
			cnt += move;
			basket_left -= move;
			basket_right -= move;
		}
		else
		{
			int move = inp - basket_right;
			cnt += move;
			basket_right += move;
			basket_left += move;
		}
	}
	cout << cnt << "\n";
	
	return 0;
}
