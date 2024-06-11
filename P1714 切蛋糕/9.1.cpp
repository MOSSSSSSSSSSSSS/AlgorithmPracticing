

#include<bits/stdc++.h>
using namespace std;

const int N = 500010,INF = 0x3f3f3f3f;
int n, m;
int a[N], sum[N], q[N], hh, tt = -1,ans = -INF;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
	{//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		while (hh <= tt && sum[q[tt]] >= sum[i-1])tt--;         //  注意i从s开始就是和  sum[i-s]比较，这里要减1%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		q[++tt] = i-1;
		while (hh <= tt && q[hh] < i - m)hh++;
		if (hh <= tt)ans = max(ans, sum[i] - sum[q[hh]]);
	}
	cout << ans;

	return 0;
}