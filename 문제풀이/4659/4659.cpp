#include <bits/stdc++.h>
using namespace std;

/*
4659 비밀번호 발음하기
https://www.acmicpc.net/problem/4659

다시 짜본 버전
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
		
		bool flag = true, is_include_vowel = false;
		int c_cnt = 0, v_cnt = 0, prev = 0;

		for (int c : inp)
		{		
			if (c == prev && c != 'e' && c != 'o')
			{
				flag = false;
				break;
			}
			if (isVowel(c))
			{
				v_cnt++;
				c_cnt = 0;
				is_include_vowel = true;
			}
			else
			{
				v_cnt = 0;
				c_cnt++;
			}
			if (c_cnt >= 3 || v_cnt >= 3)
			{
				flag = false;
				break;
			}
			prev = c;
		}
		if (!is_include_vowel)
			flag = false;
		if (flag)
			cout << "<" << inp << "> is acceptable.\n";
		else 
			cout << "<" << inp << "> is not acceptable.\n";
	}
	return 0;
}
