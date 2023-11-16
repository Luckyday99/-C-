#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input, cmp;

    cin >> input;
    cmp = input;
    reverse(cmp.begin(), cmp.end());
    if (input == cmp) cout << "1";
    else cout << "0";
}