#include <bits/stdc++.h>
using namespace std;

/*
4659 비밀번호 발음하기
https://www.acmicpc.net/problem/4659

제일 처음에 문제 잘못봐서 모음 하나 반드시 포함하는 조건을 안보고 짬
=> 길이 1일때, 2일때를 전부 예외처리함 (3개부터는 모음 없으면 어짜피 false처리 되기 때문)
*/

bool isVowel(int c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	// C++에서는 "문자열"(char*)은 큰따옴표, '문자'(char, int)는 작은따옴표
	// -> "a" 처럼 큰따옴표 입력시 int와 char*를 비교하게 되어서 fpermissive 에러 발생
}

int main()
{
	while(true)
	{
		string inp;
		cin >> inp;
		if (inp == "end") break;
		
		bool flag = true;
		int cnt = 1;
		
		if (inp.size() == 1 && !isVowel(inp[0]))
			flag = false;
		if (inp.size() == 2 && !isVowel(inp[0]) && !isVowel(inp[1]))
			flag = false;
		for (int i = 1; i < inp.size(); i++)
		{		
			if (inp[i] == inp[i - 1])
			{
				if (inp[i] == 'e' || inp[i] == 'o')
					cnt++;
				else
				{
					flag = false;
					break;
				}
			}
			else if (isVowel(inp[i]) == isVowel(inp[i - 1]))
				cnt++;
			else
				cnt = 1;
			if (cnt >= 3)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "<" << inp << "> is acceptable.\n";
		else 
			cout << "<" << inp << "> is not acceptable.\n";
	}
	return 0;
}
