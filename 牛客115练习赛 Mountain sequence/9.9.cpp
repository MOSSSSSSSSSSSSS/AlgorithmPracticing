
/*
我们从大到小考虑每个数放在序列里的方案数，相同值的数一起考虑。

首先，所有的最大值都会放在中间；

接着我们考虑第二大的值，假设出现了x 次，那我们应该有x+1 种方式放置这些数。

比如原序列是[2],插入两个1，那么就有[1,1,2],[1,2,1],[2,1,1],即在外面包裹一层。

以此类推。

因此答案就是 非最大值的数的出现次数+1的乘积。*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100010,mod = 998244353;
int T;

int main()
{
    cin >> T;
    while (T--)
    {
        int n;
        int a[N], mx = -1;
        long long ans = 1;
        map<int, int> mp;                           //  记录数组中各个元素出现次数，但不能开  1e9大小 的数组，这时：map <int,int>mp记录
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
            mp[a[i]]++;
        }
        for (auto item : mp)                   //遍历map中的元素
        {
            if (item.first != mx)
            {
                ans = (ans * (item.second + 1)) % mod;             //   注意：虽然取了模，但是ans * (item.second + 1)的计算结果可能溢出，ans要用long long
            }
        }
        cout << ans << endl;
    }

    return 0;
}