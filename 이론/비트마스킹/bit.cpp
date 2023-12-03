#include <bits/stdc++.h>
using namespace std;

/*
bitflag -> bool 배열을 요소 하나당 1 bit로 쪼개서 사용 -> 공간 절약 목적
*/

int main()
{
    cout << "크기가 n인 집합의 모든 비트를 켜기\n";
    cout << "n = 4\n";
    int bitflag = (1 << 4) - 1;
    cout << bitset<8>(bitflag) << "\n\n";

    cout << "i번째 비트 xor 연산 => ^(xor)\n";
    cout << "i = 1\n";
    cout << bitset<8>(bitflag) << " >> " << bitset<8>(bitflag ^= (1 << 0)) << "\n\n";

    cout << "i번째 비트 끄기 => &(and)\n";
    cout << "i = 3\n";
    cout << bitset<8>(bitflag) << " >> " << bitset<8>(bitflag &= ~(1 << 2)) << "\n\n";

    cout << "i번째 비트 켜기 => |(or)\n";
    cout << "i = 3\n";
    cout << bitset<8>(bitflag) << " >> " << bitset<8>(bitflag |= (1 << 2)) << "\n\n";

    cout << "i번째 비트가 켜져있는지 확인하기 => &(and)\n";
    auto func = [=](int i){
        cout << i << "번째 비트는 ";
        if (bitflag & (1 << i - 1)) cout << "켜져있음.\n";
        else cout << "꺼져있음.\n";
    };
    func(2);
    func(1);
    cout << "\n";

    cout << "경우의 수(조합)\n";
    string arr[4] = { "딸기", "당근", "수박", "참외" };
    for (int i = 0; i < (1 << 4); i++)
    {
        string ret = "";
        for (int j = 0; j < 4; j++)
        {
            if (i & (1 << j))
            {
                ret += (arr[j] + " ");
            }
        }
        if (ret == "") cout << "0 ";
        else cout << ret;
        cout << "| ";
    }
    cout << "\n";
    cout << "위에 비트 확인하는 if문과 더해서, 특정 flag 만족하는 조합만 따로 찾을수도 있음.\n";

    return 0;
}