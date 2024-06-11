

#include<bits/stdc++.h>
using namespace std;

const int N = 16010, M = 32010;
int n;
int h[N], e[M], ne[M], idx;
int num[N];
int f[N];
int ans = -2e9;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dp(int u, int father)
{
	f[u] += num[u];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			dp(j, u);
			f[u] += max(f[j], 0);
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dp(1, 0);
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	cout << ans;

	return 0;
}