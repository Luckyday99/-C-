#include <bits/stdc++.h>
using namespace std;

/*
1992 쿼드트리
https://www.acmicpc.net/problem/1992

분할 정복 (Divide & Conquar)
- 큰 문제를 여러개의 작은 문제로 나누어서 해결하는 방법
- 재귀함수 or Stack

알고리즘 자체보다 입, 출력이 더 까다로웠음...
*/

const int MAX_N = 65;
int n;
char arr[MAX_N][MAX_N];

string quadTree(int y, int x, int size)
{
	if (size == 1) return string(1, arr[y][x]);
	char cmp = arr[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (arr[i][j] != cmp)
			{
				string ret = "";
				ret += "(";
				ret += quadTree(y, x, size/2);
				ret += quadTree(y, x + size/2, size/2);
				ret += quadTree(y + size/2, x, size/2);
				ret += quadTree(y + size/2, x + size/2, size/2);
				ret += ")";
				return ret;
			}
		}
	}
	return string(1, arr[y][x]);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s = "";
		cin >> s;
		for (int j = 0; j < n; j++)
			arr[i][j] = s[j];
	}
	
	cout << quadTree(0, 0, n) << "\n";
	
    return 0;
}
