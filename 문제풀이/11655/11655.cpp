#include <bits/stdc++.h>
using namespace std;

/*
11655 ROT13
https://www.acmicpc.net/problem/11655
*/

int main()
{
    string inp;
    getline(cin,inp);
    for (int i = 0; i < inp.size(); i++)
    {
        if (inp[i] >= 'A' && inp[i] <= 'Z') 
        {
            if (inp[i] - 13 < 'A') inp[i] += 13;
            else inp[i] -= 13;
        }
        else if (inp[i] >= 'a' && inp[i] <= 'z')
        {
            if (inp[i] - 13 < 'a') inp[i] += 13;
            else inp[i] -= 13;
        }
    }
    cout << inp << "\n";

    return 0;
}