

#include<bits/stdc++.h>
using namespace std;

const int N = 20,M = 3000;
int n, k;
int now[N], max_now,Max, idx = 1,ans[N];
int f[M];

int dp()
{
	for (int i = 1; i < M; i++)
		f[i] = M;
	f[0] = 0;
	for (int i = 1;; i++)
	{
		for (int j = 1; i>=now[j]&&j <= idx; j++)
			f[i] = min(f[i], f[i - now[j]] + 1);
		if (f[i] > n)
			return i - 1;
	}
}

void dfs()
{
	if (idx == k)
	{
		if (max_now > Max)
		{
			Max = max_now;
			for (int i = 1; i <= idx; i++)
				ans[i] = now[i];
		}
		return;
	}

	for (int i = now[idx] + 1; i <= max_now + 1; i++)
	{
		now[++idx] = i;
		int t = max_now;
		max_now = dp();
		dfs();
		idx--;
		max_now = t;
	}
}

int main()
{
	cin >> n >> k;
	now[1] = 1;
	max_now = n;
	dfs();

	for (int i = 1; i <= k; i++) //  注意idx最后都是在第二个数（因为是深度优先搜索），打印ans时不能循环到idx+1,这样永远只打印前两个数,原来写的i<=idx+1
		cout << ans[i] << ' ';
	cout << endl << "MAX=" << Max;     

	return 0;
}