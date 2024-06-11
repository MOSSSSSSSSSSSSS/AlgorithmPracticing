
#include<bits/stdc++.h>
#define int long long
using namespace std;
int qp[25][5] = { 0, 0, 0, 0, 0,
0, 1, 2, 3, 4,
0, 1, 2, 4, 3,
0, 1, 3, 2, 4,
0, 1, 3, 4, 2,
0, 1, 4, 2, 3,
0, 1, 4, 3, 2,
0, 2, 1, 3, 4,
0, 2, 1, 4, 3,
0, 2, 3, 1, 4,
0, 2, 3, 4, 1,
0, 2, 4, 1, 3,
0, 2, 4, 3, 1,
0, 3, 1, 2, 4,
0, 3, 1, 4, 2,
0, 3, 2, 1, 4,
0, 3, 2, 4, 1,
0, 3, 4, 1, 2,
0, 3, 4, 2, 1,
0, 4, 1, 2, 3,
0, 4, 1, 3, 2,
0, 4, 2, 1, 3,
0, 4, 2, 3, 1,
0, 4, 3, 1, 2,
0, 4, 3, 2, 1 };
int qp2[7][4] = { 
0, 0, 0, 0,
0, 1, 2, 3,
0, 1, 3, 2,
0, 2, 1, 3,
0, 2, 3, 1,
0, 3, 1, 2,
0, 3, 2, 1 };
int a[5], b[4];
int js[4];
signed main()
{
    for (int i = 1; i <= 4; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= 3; i++)
    {
        char ch;
        cin >> ch;
        if (ch == '*') js[i] = 2;
        else js[i] = 1;
    }
    int ans = 0x7fffffffffffffff;
    for (int i = 1; i <= 24; i++)
    {
        if (js[1] == 1) b[1] = a[qp[i][1]] + a[qp[i][2]];
        else b[1] = a[qp[i][1]] * a[qp[i][2]];
        b[2] = a[qp[i][3]];
        b[3] = a[qp[i][4]];
        for (int j = 1; j <= 6; j++)
        {
            int z1, z2;
            if (js[2] == 1) z1 = b[qp2[j][1]] + b[qp2[j][2]];
            else z1 = b[qp2[j][1]] * b[qp2[j][2]];
            if (js[3] == 1) z2 = z1 + b[qp2[j][3]];
            else z2 = z1 * b[qp2[j][3]];
            ans = min(ans, z2);
        }
    }
    cout << ans;
    return 0;
}