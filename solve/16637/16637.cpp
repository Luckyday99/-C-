#include <bits/stdc++.h>
using namespace std;

/*
16637 괄호 추가하기
https://www.acmicpc.net/problem/16637

브루트포스
연산자 순서 정하는 순열문제인줄 알았는데 구현하다보니 이미 계산된 값 처리하는게 너무 이상해져서 다른 방법으로 선회

다른 방법으로 하긴 했는데
&nums[i] = &nums[i + 1] 이런 식으로 사용된 값은 포인터 자체를 둘중 하나로 덮어버릴 수는 없나 싶어서 찾아볼 예정
*/

int n, ret = -987654321;
string s;
vector<int> nums;
vector<char> opers;

int calc(int left, int right, char oper)
{
    if (oper == '+') return left + right;
    if (oper == '-') return left - right;
    if (oper == '*') return left * right;
}

void solve(int here, int init)
{
    if (here == opers.size())
    { 
        ret = max(ret, init); 
        return;
    }  
    solve(here + 1, calc(init, nums[here + 1], opers[here]));

    if (here + 2 <= opers.size())
    {
        int temp = calc(nums[here + 1], nums[here + 2], opers[here + 1]); 
        solve(here + 2, calc(init, temp, opers[here]));  
    } 
    return;
} 

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (i % 2) opers.push_back(s[i]);
        else nums.push_back(s[i] - '0');
    }
    solve (0, nums[0]);
    cout << ret << "\n";

    return 0;
}