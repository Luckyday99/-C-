#include <bits/stdc++.h>
using namespace std;

/*
9935 문자열 폭발
https://www.acmicpc.net/problem/9935
*/

string str, boom, ret;

int main()
{
    cin >> str >> boom;
    for (char c : str)
    {
        ret += c;
        if (ret.size() >= boom.size() && ret.substr(ret.size() - boom.size(), boom.size()) == boom)
        {
            ret.erase(ret.end() - boom.size(), ret.end());
        }
    }
    if (ret.empty()) cout << "FRULA\n";
    else cout << ret << '\n';

    return 0;
}