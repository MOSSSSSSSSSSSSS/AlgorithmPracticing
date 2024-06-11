

#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10, M = 6e5 + 10;
int dfn[N], low[N], timestamp;
int stk[N], top;

int edcc, id[N];
bool is_bridge[M];

int h[N], e[M], ne[M], idx;
int n, m;
vector<int> edge[N];
int ans;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (dfn[j] == 0)
		{
			tarjan(j, i);
			low[u] = min(low[u], low[j]);
			if (dfn[u] < low[j])is_bridge[i] = is_bridge[i ^ 1] = true;  // 点双 是大于等于
		}
		else if (i != (from ^ 1))
			low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u])
	{
		edcc++;
		int y;
		do {
			y = stk[top--];
			id[y] = edcc;
		} while (y != u);
	}
}
int dfs(int u, int father)
{
	int d1 = 0, d2 = 0;
	for (auto item : edge[u])
	{
		if (item != father)
		{
			int d = dfs(item, u) + 1;
			if (d >= d1)d2 = d1, d1 = d;//////////  大于等于!!!!!
			else if (d > d2 && d < d1)d2 = d;
		}
	}
	ans = max(ans, d1 + d2);
	return d1;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y), add(y, x);
	}
	tarjan(1, -1);
	for (int i = 0; i < idx; i+=2)
	{
		int a = e[i], b = e[i ^ 1];
		if (id[a] != id[b])edge[id[a]].push_back(id[b]), edge[id[b]].push_back(id[a]);
	}
	dfs(1,0);
	cout << ans;

	return 0;
}