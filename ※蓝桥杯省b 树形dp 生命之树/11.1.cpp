

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10,M = 2e5+10;
int h[N], e[M], ne[M], idx;
int n;
int sc[N];
long long f[N];
long long ans;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dp(int u,int father)
{
	f[u] += sc[u];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			dp(j, u);
			f[u] += max(f[j], 0LL);
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> sc[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b),add(b,a);
	}
	dp(1,0);
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	ans = max(ans, 0LL);
	cout << ans;

	return 0;
}