#include <bits/stdc++.h>
using namespace std;

/*
9934 완전 이진 트리
https://www.acmicpc.net/problem/9934

재귀함수 구현
*/

int k, arr[1030], MAX_N;
vector<int> ret[10];

void go(int start, int end, int level)
{
    if (start == end)
    {
        ret[level].push_back(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    ret[level].push_back(arr[mid]);
    go(start, mid - 1, level + 1);
    go(mid + 1, end, level + 1);
    return;
}

int main()
{
    cin >> k;
    MAX_N = static_cast<int>(pow(2, k)) - 1;
    for (int i = 0; i < MAX_N; i++)
    {
        cin >> arr[i];
    }
    go(0, MAX_N - 1, 0);
    for (int i = 0; i < k; i++)
    {
        for (int j : ret[i]) cout << j << " ";
        cout << "\n";
    }

    return 0;
}