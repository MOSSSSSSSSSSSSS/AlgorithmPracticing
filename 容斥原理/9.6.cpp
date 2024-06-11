

//   时间复杂度 2的n次方，n是集合个数
//   集合的并集（去重） = 单个 - 两个的交集+三个的交集-四个的交集+五个的交集……
//   例：能被整除的数，如1到10中能被2或3整除的数，简单方法是遍历1到10，看能不能被2或3整除，复杂度m*n
//   容斥原理就是，1到10中2的倍数的个数+1到10中3的倍数的个数-1到10中即是2的倍数又是3的倍数的个数
//   1到10中2的倍数的个数 = 10 / 2 向下取整；1到10中3的倍数的个数 = 10 / 3 向下取整，2和3的公倍数的个数由于2和3是指数，所以就是6的倍数的个数，10 / 6 向下取整
//   时间复杂度2的m次方
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 20;
int n, m;
int a[N];
LL ans;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)cin >> a[i];
	for (int i = 1; i < 1 << m; i++)   //  i小于2的m次方，用每一位代表一个状态
	{
		int cnt = 0;     //  几个集合 ，奇数还是偶数
		LL t = 1;           //   质数乘积
		for (int j = 0; j < m; j++)
		{
			if (i >> j & 1)
			{
				if (t * a[j] > n)
				{
					t = -1;
					break;
				}
				t *= a[j];
				cnt++;
			}
		}
		if (t == -1)continue;
		if (cnt & 1)ans += n / t;         //  判断奇数偶数，用二进制最后一位就行
		else ans -= n / t;
	}
	cout << ans;

	return 0;
}