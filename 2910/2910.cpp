#include <bits/stdc++.h>
using namespace std;

/*
2910 빈도 정렬
https://www.acmicpc.net/problem/2910
*/

int n, c, msg[1004];
vector<pair<int, int>> v_cnt_rev;
map<int, int> mp_cnt, mp_msg_first;

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
	{
		cin >> msg[i];
		mp_cnt[msg[i]]++;
		if (mp_msg_first[msg[i]] == 0) mp_msg_first[msg[i]] = i + 1;
        // map 에서 값 할당 안되어 있을 때, int = 0, string = 빈 문자열
        // i + 1 안해주면 0 들어갈 때 할당 안된 값으로 인식하여 오류
	}
	for (auto it : mp_cnt)
	{
		v_cnt_rev.push_back({it.second, it.first});
	}
		
	sort(v_cnt_rev.begin(), v_cnt_rev.end(),
		[](pair<int, int> a, pair<int, int> b) -> bool
		{
			if (a.first == b.first)
				return (mp_msg_first[a.second] < mp_msg_first[b.second]);
			return (a.first > b.first);
		}
	);
	for (auto i : v_cnt_rev)
	{
		for (int j = 0; j < i.first; j++)
		{
			cout << i.second << " ";
		}
	}

    return 0;
}
