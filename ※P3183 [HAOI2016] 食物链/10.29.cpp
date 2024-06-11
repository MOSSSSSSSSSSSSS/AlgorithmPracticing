

//  dfsËÑË÷£¬¼ÇÒä»¯ËÑË÷

#include<bits/stdc++.h>
using namespace std;

const int N = 100010, M = 200010;
int n, m;
int h[N], e[M], ne[M], idx;
int num[N];
int din[N], dout[N];
int ans;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if(!num[j])
		{
			dfs(j);
			if (!dout[j])num[j] = 1;
		}
		num[u] += num[j];
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		din[b]++, dout[a]++;
	}
	for (int i = 1; i <= n; i++)
		if (!din[i])
		{
			dfs(i);
			ans += num[i];
		}
	cout << ans;

	return 0;
}

