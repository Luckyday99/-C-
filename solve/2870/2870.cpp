#include <bits/stdc++.h>
using namespace std;

/*
2870 수학 숙제
https://www.acmicpc.net/problem/2870

자료형의 범위 생각할 것
최대 100글자
->  int : 2147483647 / 9자리까지만 가능
    longlong : 18자리까지 가능
    => big int / string 으로 비교

if문 중첩으로 계속 쓰는게 답이 아닌 줄 알고 계속 고민했었는데 이게 최선이었음
-> 그냥 크게 고민하지 말고 예외처리 일단 if문으로 처리해서 일단 구현해볼것
*/

int n;
string inp;
vector<string> v_nums;

void push_nums(string& num)
{
    while (true)
    {
        if (num.size() && num.front() == '0')
            num.erase(num.begin());
        else break;
    }
    if (num.size() == 0)
        v_nums.push_back("0");
    else
        v_nums.push_back(num);
    num = "";
}

int main()
{
    cin >> n;
    while (n--)
    {
        string tmp = "";
        cin >> inp;
        for (int i = 0; i < inp.size(); i++)
        {
            if (isdigit(inp[i])) tmp += inp[i];
            else if (tmp.size()) push_nums(tmp);
        }
        if (tmp.size()) push_nums(tmp);
    }
    sort(v_nums.begin(), v_nums.end(),
        [](string a, string b) -> bool
        {
            if (a.size() == b.size()) return a < b;
            // string끼리 비교할때는 첫자리부터 아스키코드 비교
            return (a.size() < b.size());
        });
    for (string i : v_nums)
        cout << i << "\n";

    return 0;
}