#include <bits/stdc++.h>
using namespace std;

/*
17071 숨바꼭질 5
https://www.acmicpc.net/problem/17071

bfs, 풀르드필(floodfill)

오답 1 http://boj.kr/702ac9e68c0344ceb14553c0339dd439
큐 이용해서 연결리스트방식 비슷하게 해보려고 했는데 큐가 생각보다 크기가 크다는 걸 알았다.
queue 500004개를 전역에 선언한 저 코드에서도 답은 빨리 나왔는데 마지막 return 0에서 대부분의 시간을 씀 / main의 지역변수로 선언하면 시그먼트에러
-> 연결행렬로 하기에는 50만 * 50만이라 크기가 너무 커져서 다른 방법 사용
-> 수빈 이동 방법이 +1, -1, *2 -> 같은 자리에서 t 2번 증가할때마다 +1, -1 반복해서 똑같은 자리로 되돌아 올 수 있음
    = 수빈이의 홀수 / 짝수 최단도착시간만 저장하면 됨 (동생 홀수 / 짝수 최단도착시간이 수빈이보다 크면 수빈이가 +1, -1 반복하다가 만날 수 있음)
+) 풀르드필 사용해서 bfs 두개 동시에 돌리기 가능
*/

int n, k, visited[2][500004], ret = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    if (n == k)
    {
        cout << "0\n";
        return 0;
    }
    queue<int> q;
    visited[0][n] = 1;
    q.push(n);
    // 풀르드필 -> 깊이 달라질 때 구분 가능 => 동생 / 수빈 동시에 bfs 가능
    for (int t = 1; q.size(); t++)
    {
        k += t;
        if (k > 500000) break;
        if (visited[t % 2][k])
        {
            ret = t;
            break;
        }
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            int x = q.front();
            q.pop();
            for (int nx : {x - 1, x + 1, x * 2})
            {
                if (nx < 0 || nx > 500000 || visited[t % 2][nx]) continue;
                visited[t % 2][nx] = visited[(t + 1) % 2][x];
                if (nx == k)
                {
                    cout << t << "\n";
                    return 0;
                }
                q.push(nx);
            }
        }
    }
    cout << ret;
    
    return 0;
}