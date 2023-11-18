#include <bits/stdc++.h>
using namespace std;

/*
2852 NBA 농구
https://www.acmicpc.net/problem/2852
*/

int n, team, goal_time, cur_time, a_cnt, b_cnt, a_sum, b_sum;
string inp_time;

int strToInt(string s)
{
    return stoi(s.substr(0,2)) * 60 + stoi(s.substr(3,2));
}

string printSum(int i)
{
    string pmin = "00" + to_string(i / 60);
    string psec = "00" + to_string(i % 60);
    return pmin.substr(pmin.size() - 2, 2) + ":" +  psec.substr(psec.size() - 2, 2) + "\n";
}

void addTime()
{
    if (a_cnt > b_cnt)
        a_sum += cur_time - goal_time;
    else if (b_cnt > a_cnt)
        b_sum += cur_time - goal_time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while (n--)
    {
        cin >> team >> inp_time;
        cur_time = strToInt(inp_time);
        addTime();
        goal_time = cur_time;
        if (team == 1) a_cnt++;
        else b_cnt++;
    }
    {
        cur_time = strToInt("48:00");
        addTime();
    }
    cout << printSum(a_sum);
    cout << printSum(b_sum);

    return 0;
}
