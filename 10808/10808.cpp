#include <bits/stdc++.h>
using namespace std;

/*
10808 알파벳 개수
https://www.acmicpc.net/problem/10808
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ret[26] = {0,};
    string input = "";
    cin >> input;

    for (int i = 0; i < input.size(); i++) ret[input[i]-'a']++;
    for (int i : ret) cout << i << " ";

    return 0;
}