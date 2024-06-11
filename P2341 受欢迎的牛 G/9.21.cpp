

#include<bits/stdc++.h>
using namespace std;

const int N = 10010, M = 50010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt,Size[N];
int dout[N];

void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;
	in_stk[u] = true;
	for (int i = h[u]; ~i; i = ne[i])
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
			in_stk[y] = false;
			id[y] = scc_cnt;
			Size[scc_cnt]++;
		} while (y != u);
	}
}

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
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
				dout[id[i]]++;
		}
	}
	int cnt = 0,ans = 0;
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (dout[i] == 0)
		{
			cnt++;
			ans += Size[i];
		}
	}
	if (cnt > 1)cout << 0;
	else cout << ans;

	return 0;
}