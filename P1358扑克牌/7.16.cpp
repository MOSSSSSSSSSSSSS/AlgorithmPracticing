
//答案是C(n,m)%mod，可以用二维数组存储杨辉三角，求组合数，a[i][j] = a[i-1][j-1]+a[i-1][j]  数可能很大，用ll

#include<iostream>
using namespace std;

typedef long long ll;

const ll N = 10010ll, M = 110ll,mod = 10007ll;

ll n, m,ans = 1ll;
ll yang_hui[N][M];

int main()
{
	cin >> n >> m;

	for (int i = 0; i <= n; i++)yang_hui[i][0] = 1ll;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j < i)yang_hui[i][j] = (yang_hui[i - 1][j - 1] + yang_hui[i - 1][j]) % mod;
			else yang_hui[i][j] = 1ll;
		}
	}//有个i-1，j-1，但不从1开始循环，为了下标不出现负数，就把j
	//从1开始，j = 0的直接全赋值为1
	//杨辉三角直接从下标0开始写，杨辉三角里第一个数本来也是C(0,0)
	//先把杨辉三角算出来，后面用组合数时直接用
	//也要模mod，否则会超出ll，有负数出现


	//(a + b) % p = (a % p + b % p) % p （1）
	//(a - b) % p = (a % p - b % p) % p （2）
	//(a * b) % p = (a % p * b % p) % p （3）是上面和下面为什么那样取模的原因
	//	a ^ b % p = ((a % p) ^ b) % p （4）

	while (m--)
	{
		int t;
		cin >> t;
		ans = (ans * yang_hui[n][t])%mod;   // 说是输出次数模mod的值，是  每次计算  都模一次，最后输出
		n -= t;
	}

	cout << ans;

	return 0;
}
