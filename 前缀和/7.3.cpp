
//前缀和，用于求数组中从第l个到第r个数的和，1<=l<=r<=n，数组是a1，a2。。。。。。an。
//定义前缀和数组s0 = 0
//当需要多次求和时，如果每次求和都循环一次，每次都是O（n）复杂度，但如果先算出前缀和数组，每次只需要计算S（r） - S（l - 1），每次都是O（1）复杂度

//加上  ios::sync_with_stdio(false);   可以使cin速度变快，但不能使用scanf了


#include<iostream>
using namespace std;

const int N = 100010;
int n, m, a[N], s[N];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];

	while (m--)//有m个询问
	{
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}

	return 0;
}