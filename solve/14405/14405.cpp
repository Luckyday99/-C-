#include <bits/stdc++.h>
using namespace std;

/*
14405 피카츄
https://www.acmicpc.net/problem/14405
*/

string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    string tmp = "";
    for (char c : str)
    {
        if (c == 'i' && tmp == "p") tmp = "";
        else if (c == 'a' && tmp == "k") tmp = "";
        else if (c == 'u' && tmp == "ch") tmp = "";
        else tmp += c;
    }
    if (tmp != "") cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
