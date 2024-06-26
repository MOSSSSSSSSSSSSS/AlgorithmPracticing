#define _CRT_SECURE_NO_WARNINGS

//用递归写动态规划有一个学名叫：记忆化搜索

//指 状态表示 二维 ，构成一个区间，如石子合并
//石子合并状态表示：f[i][j]指从第i个到第j个  合并成一个  的所有解决方法中，付出的最小代价
//状态转移方程：合并成一个的前一个状态都是由两个合并成一个  根据这两个 一个是由 i 到 k合并而成，一个是由 k+1到 j 合并而成，k属于 i 到 j-1 的不同取值 构成所有情况
//f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+最后两堆石子合并的代价)
//而最后两堆石子合并的代价 = i到j所有石子的重量 可以用   前缀和数组来算  ，由于要多次计算，所以用前缀和数组可以很方便
//时间复杂度 = O(n2*n),二位状态数n方，再乘以计算每个状态的，计算每个状态需要枚举 k i到j-1，复杂度是n，所以总的是O（n3）
#include<bits/stdc++.h>
using namespace std;

const int N = 310, INF = 1e9;

int n;
int a[N], s[N];//    可以用一个数组来存
int f[N][N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];

	for (int i = n; i >= 1; i--)    //写完后看看要求出某个值，需要用到什么，需要用到的需要在这之前求出来，因此循环顺序会不同
	{
		for (int j = i; j <= n; j++) //j在i右边
		{
			for (int k = i; k <= j - 1; k++)
			{
				if (k == i)
					f[i][j] = INF;    // 原来是0，求最小值不可能是0，初始化成非常大的数，在一开始的时候初始化
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	}                         //  yxc用的循环不同，他的使用区间长度的循环，好像区间DP可以用，但由于这个可以 ，就没有看他的，有空可以再看看他的

	cout << f[1][n];

	return 0;
}