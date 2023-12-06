#include <bits/stdc++.h>
using namespace std;

/*
14890 경사로
구현

일단 되는대로 풀어봤는데 맞아서 그냥 올림
1. if 분기 저렇게 복잡하게 안하고 풀 방법이 있는지?
2. 람다함수로 대충 처리한 부분 저렇게 말고 다른 방법이 있는지
*/

using pii = pair<int, int>;
int n, l, arr[104][104], ret;

void solve(int line, int value)
{
    int cnt = 1, flag = true;
    auto init = [=](int i) -> pii
    {
        if (value) return {arr[line][i - 1], arr[line][i]};
        else return {arr[i - 1][line], arr[i][line]};
    };
    for (int i = 1; i < n; i++)
    {
        pii a = init(i);
        if (a.first == a.second) cnt++;
        else if (a.first + 1 == a.second && cnt >= l) cnt = 1;
        else if (a.first - 1 == a.second && cnt >= 0) cnt = -l + 1;
        else
        {
            flag = false;
            break;
        }
    }
    if (flag && cnt >= 0) ret++;
}

int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        solve(i, 0);
        solve(i, 1);
    }
    cout << ret << "\n";

    return 0;
}