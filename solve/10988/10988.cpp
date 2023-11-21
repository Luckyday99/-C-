#include <bits/stdc++.h>
using namespace std;

/*
10988 팰린드롬인지 확인하기
https://www.acmicpc.net/problem/10988
*/

int main()
{
    string input, cmp = "";
    cin >> input;

    int len = input.length();
    if (len%2 == 0)
    {
        cmp = input.substr(0, len/2);
        input.erase(0, len/2);
    }
    else
    {
        cmp = input.substr(0, (len-1)/2);
        input.erase(0, (len+1)/2);
    }
    reverse(cmp.begin(), cmp.end());
    if (cmp == input) cout << "1";
    else cout << "0";
    
    return 0;
}