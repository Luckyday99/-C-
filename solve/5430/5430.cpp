#include <bits/stdc++.h>
using namespace std;

/*
5430 AC
https://www.acmicpc.net/problem/5430

Deque, 파싱
파싱 : 데이터에서 원하는 데이터만을 특정 패턴이나 순서로 추출하는 것
*크롤링 != 파싱
*크롤링 : 정보를 수집, 분류 | *파싱 : 정보를 가공하여 추출

시행착오가 많았음
1. vector로 받았다가
    => R나오면 pop_front하길래 deque로 바꿨고
2. R 나올때마다 reverse써서 했더니 시간초과
    => bool rev에 뒤집을지 안뒤집을지 저장해서 마지막에 한번만 뒤집었음
3. n == 0일때 -> D 입력되면 error << 여기서 한번 틀리고
4. D없으면 error 아님 << 여기서 한번 더 틀림
*/

int t, n;
string p, inp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        deque<int> dq;
        cin >> p >> n >> inp;
        int tmp = 0;
        if (n)
        {
            for (char c : inp)
            {
                if (c >= '0' && c <= '9') tmp = tmp * 10 + (c - '0');
                else if (c == ',' || c == ']')
                {
                    dq.push_back(tmp);
                    tmp = 0;
                }
                else if (c == '[') continue;
            }
        }
        bool rev = false, error = false;
        for (char c : p)
        {
            if (c == 'R') rev = !rev;
            else if (c == 'D')
            {
                if (dq.empty())
                {
                    error = true;
                    break;
                }
                else if (rev) dq.pop_back();
                else dq.pop_front();
            }
        }
        if (error) cout << "error\n";
        else
        {
            if (rev) reverse(dq.begin(), dq.end());
            cout << '[';
            int dqsize = dq.size();
            for (int i = 0; i < dqsize; i++)
            {
                cout << dq[i];
                if (i != dqsize - 1) cout << ',';
            }
            cout << "]\n";
        }
    }
    return 0;
}