#include <bits/stdc++.h>
using namespace std;

/*
10709 기상캐스터
https://www.acmicpc.net/problem/10709
*/

int h, w, idx;
string inp;

int main()
{
    cin >> h >> w;
    while (h--)
    {
        cin >> inp;
        for (int i = 0; i < w; i++)
        {
            idx = i;
            while (true)
            {
                if (idx < 0)
                {
                    cout << "-1 ";
                    break;
                }
                if (inp[idx] == 'c')
                {
                    cout << i - idx << " ";
                    break;
                }
                idx--;
            }
        }
        cout << "\n";
    }
    return 0;
}