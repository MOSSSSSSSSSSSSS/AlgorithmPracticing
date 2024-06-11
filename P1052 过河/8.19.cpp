

            //  题目中数据范围1e9太大，开这样的数组会出错，只需要知道哪些坐标有石子就行，所以可以离散化，yxc的离散化是用那些点的单调上升序列
        //    用它在序列里的下标表示某个数，再建一个新数组，下标就是某个数转换后的下标，用来存储东西

//  这个题用的是缩点，不是离散化
//可以发现当s<t时， s和t一定会重合，而这以后的每个点都可以到达， 所以我们只需将每两个石头超过 s×t 的距离缩成s×t就可以了
#include<bits/stdc++.h>
using namespace std;

const int N = 105 * 90,M = 110,INF = 0x3f3f3f3f;
int l, s, t, m;
int bridge[N],stone[M],backup[M];
int dp[N];
int ans = INF;

int main()
{
    cin >> l >> s >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> stone[i];
        backup[i] = stone[i];
    }
    sort(stone + 1, stone + m+1);
    sort(backup + 1, backup + m + 1);
    if (s == t)
    {
        int cnt = 0;
        for (int i = 1; i <= m; i++)
            if (stone[i] % s == 0)
                cnt++;
        cout << cnt;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        if (stone[i] - backup[i - 1] > s * t)
            stone[i] = stone[i - 1] + s * t;
        else
            stone[i] = stone[i - 1] + stone[i] - backup[i - 1];
        bridge[stone[i]] = 1;
    }
    if (l - backup[m] > s * t)
        l = stone[m] + s * t;                   //  21到38行%%%%%压缩路径%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    else
        l = stone[m] + l - backup[m];
    for (int i = 0; i <= l-1+t; i++)            //  初始化极大值，注意终点在哪
        dp[i] = INF;
    dp[0] = 0;
    for (int i = 1; i <= l - 1 + t; i++)
    {
        /*for (int j = i - s; j >= 0 && j >= i - t; j--)
            dp[i] = min(dp[i], dp[j]);
        if (bridge[i] == 1)
            dp[i]++;*/
        for (int j = i - s; j >= 0 && j >= i - t; j--)
        {
            if (bridge[i] == 1)
                dp[i] = min(dp[i], dp[j]+1);
            else
                dp[i] = min(dp[i], dp[j]);
        }
    }
    for (int i = l; i <= l - 1 + t; i++)
        ans = min(ans, dp[i]);

    cout << ans;

    return 0;
}
