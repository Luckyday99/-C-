#include <bits/stdc++.h>
using namespace std;

/*
1940 аж╦Ы
https://www.acmicpc.net/problem/1940
а╤гу 
*/

int n, m, cnt, nums[15004]; 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> nums[i];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (nums[i] + nums[j] == m) cnt++;
	}
	cout << cnt << "\n";
	
	return 0;
}
