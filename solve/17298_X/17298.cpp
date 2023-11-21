#include <bits/stdc++.h>
using namespace std;

/*
17298 오큰수
https://www.acmicpc.net/problem/17298

skack, 구현

구현문제 풀때
1. 브루트포스 가능한지 생각 ** <= 이게 제일 안되는듯... 바로 2번으로 넘어가서 고생하던가 가능한지 판단도 안하고 바로 정답 제출 해버리던가
2. 안되면 다른걸로
3. 예외 생각(끝값 등)
짝짓기, 폭발 등 -> Stack 꼭 생각 해볼것! **

짝짓기 문제 : 특정 입력 들어왔을 때 기존 값이랑 짝 지어서 결과가 결정되는 문제?
ex) 괄호 문제(9012, 4949 등)
*/

int n, arr[1000004], ret[1000004];
stack<int> stk; 

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		while (stk.size() && arr[stk.top()] < arr[i])
		{
			ret[stk.top()] = arr[i];
			stk.pop();
		}
		stk.push(i);
	}
	for (int i = 0; i < n; i++) cout << ret[i] << " ";

	return 0;
}
