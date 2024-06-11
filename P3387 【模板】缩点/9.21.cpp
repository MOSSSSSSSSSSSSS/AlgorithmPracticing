

#include<bits/stdc++.h>
using namespace std;

const int N = 10010, M = 100010;
int n, m;
int h[N], e[M], ne[M], idx;
int w[N],w2[N];
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
int dp[N];
vector<int> a[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (in_stk[j])
			low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u])
	{
		int y;
		scc_cnt++;
		do {
			y = stk[top--];
			id[y] = scc_cnt;
			w2[scc_cnt] += w[y];
			in_stk[y] = false;
		} while (y != u);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		add(u, v);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = h[i]; ~j; j = ne[j])
		{
			int k = e[j];
			if (id[i] != id[k])
			{
				a[id[i]].push_back(id[k]);
			}
		}
	}
	for (int i = 1; i <= scc_cnt; i++)
		dp[i] = w2[i];                              //  注意初始化 dp 数组
	for (int i = scc_cnt; i >= 1; i--)
		for (int j = 0; j < a[i].size(); j++)
			dp[a[i][j]] = max(dp[a[i][j]], dp[i] + w2[a[i][j]]);
	int ans = 0;
	for (int i = 1; i <= scc_cnt; i++)
		ans = max(ans, dp[i]);
	cout << ans;

	return 0;
}