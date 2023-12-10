#include <bits/stdc++.h>
using namespace std;

/*
15353 큰 수 A + B (2)
https://www.acmicpc.net/problem/15353
*/

string A, B, ret;
int sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;
    while (A.length() || B.length() || sum)
    {
        if (A.length())
        {
            sum += A.back() - '0';
            A.pop_back(); 
        }
        if (B.length())
        {
            sum += B.back() - '0';
            B.pop_back();
        }
        ret += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    cout << ret << "\n";

    return 0;
}