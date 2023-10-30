#include <bits/stdc++.h>
using namespace std;

/*
9996 한국이 그리울 땐 서버에 접속하지
https://www.acmicpc.net/problem/9996
*/

int main()
{
    int n;
    string pat, name, first, last;

    cin >> n;
    cin >> pat;

    int pos = pat.find("*");
    first = pat.substr(0, pos);
    last = pat.substr(pos + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> name;
        if (first.size() + last.size() > name.size())
            cout << "NE" << "\n";
        else
        {
            if (name.substr(0, first.size()) == first && name.substr(name.size() - last.size()) == last)
                cout << "DA" << "\n";
            else
                cout << "NE" << "\n";
        }
    }

    return 0;
}