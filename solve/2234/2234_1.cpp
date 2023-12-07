#include <bits/stdc++.h>
using namespace std;

/*
2234 성곽
https://www.acmicpc.net/problem/2234

비트마스킹, dfs
2번 풀이
1번 풀이에서 접해있는 다른 방을 찾는 방법을 바꾸었음

1번 풀이는 dfs에서 방 크기와 동시에, 이미 구한 방 중에서 접해있는 방이 있으면 저장하도록 함
2번 풀이는 그냥 사이즈만 따로 구한 다음, 다시 반복문 돌려서 옆 지역이 다른 방이면 계산하도록 하였음
1번, 2번 모두 visited 배열에 어느 방인지 저장되어 있으므로, 굳이 dfs 안에서 안찾아도 되었음
*/

int n, m, arr[52][52], visited[52][52], ret1, ret2, ret3;
const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };
vector<int> sizes;

// 출력 바뀜 (pii {size, counted} -> int size)
int dfs(int y, int x)
{
    int size = 1;
    for (int i = 0; i < 4; i++)
    {
        if (arr[y][x] & (1 << i)) continue;
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        visited[ny][nx] = visited[y][x];
        size += dfs(ny, nx);
    }
    return size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                ret1++;
                visited[i][j] = ret1;
                sizes.push_back(dfs(i, j));
                ret2 = max(ret2, sizes[ret1 - 1]);
            }
        }
    }
    // 바뀐부분
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n && visited[i][j] != visited[i + 1][j])
            {
                ret3 = max(ret3, sizes[visited[i][j] - 1] + sizes[visited[i + 1][j] - 1]);
            }
            if (j + 1 < m && visited[i][j] != visited[i][j + 1])
            {
                ret3 = max(ret3, sizes[visited[i][j] - 1] + sizes[visited[i][j + 1] - 1]);
            }
        }
    }
    cout << ret1 << "\n" << ret2 << "\n" << ret3 << "\n";

    return 0;
}