

//完全背包解法：每一个数使用次数是无限的f[i][j]集合是从前i个物品中选，容量恰好为j的所有方案，属性：注意是数量
//状态转移方程：第i个拿0个。。。。一直到拿s个（小于等于背包容量）f[i][j] = 数量要都加起来，不是max（），f[i-1][j]+f[i-1][j-i]+...+f[i-1][j-s*i]
//再按照完全背包方法优化：写出f[i][j-i]，所以f[i][j] = f[i-1][j]+f[i][j-i]
//再删掉第一维，f[j] = f[j] + f[j-1],注意循环顺序
#include<bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N];

int main()
{
	cin >> n;

	f[0] = 1;   //当j是0时，只要一个都不选就是0，所以有1种。

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			f[j] = (f[j] + f[j - i]) % mod;
		}
	}

	cout << f[n];

	return 0;
}
//第二种做法，状态表示：f[i][j]表示和是i，用j个数表示,属性是数量
//状态转移方程：分为所有方案中最小是1和所有方案中最小大于1两类，如5用2个数表示，5 = 3 + 2，5 = 4 + 1
//f[i][j] = f[i-1][j-1]这个是最小是1，把1去掉，+f[i-j][j]这个是最小大于1，将方案中每个数减1
#include<bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N][N];

int main()
{
	scanf("%d", &n);

	f[0][0] = 1;  //按状态表示的意义进行初始化

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += f[n][i];
		res %= mod;
	}
	cout << res;

	return 0;
}