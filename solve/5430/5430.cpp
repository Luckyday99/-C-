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
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        deque<int> dq;
        cin >> p >> n >> inp;
        int tmp = 0;
        for (int i = 1; i + 1 < inp.size(); i++)
        {
            if (inp[i] == ',')
            {
                dq.push_back(tmp);
                tmp = 0;
            }
            else tmp = tmp * 10 + (inp[i] - '0');
        }
        if (tmp != 0) dq.push_back(tmp);
        bool isReverse = false, isError = false;
        for (char c : p)
        {
            if (c == 'R') isReverse = !isReverse;
            else
            {
                if (dq.empty())
                {
                    isError = true;
                    break;
                }
                if (isReverse) dq.pop_back();
                else dq.pop_front();
            }
        }
        if (isError) cout << "error\n";
        else
        {
            if (isReverse) reverse(dq.begin(), dq.end());
            string ret = "[";
            int dqsize = dq.size();
            for (int i : dq)
            {
                ret += to_string(i);
                ret += ',';
            }
            if (ret.length() > 1) ret.erase(ret.end() - 1);
            ret += "]\n";
            cout << ret;
        }
    }
    return 0;
}