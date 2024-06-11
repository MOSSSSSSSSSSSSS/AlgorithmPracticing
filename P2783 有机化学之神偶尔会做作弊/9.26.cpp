

#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;
int n, m,tot;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int id[N], edcc_cnt;
bool is_bridge[M];
bool check[N][N];
vector<int> a[N];
int dep[N];
int fa[N][15];
bool st[N];

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
		if (!dfn[j])
		{
			tarjan(j, i);
			low[u] = min(low[u], low[j]);
			if (dfn[u] < low[j])
				is_bridge[i] = is_bridge[i ^ 1] = true;
		}
		else if (i != (from ^ 1))
			low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u])
	{
		edcc_cnt++;
		int y;
		do {
			y = stk[top--];
			id[y] = edcc_cnt;
		} while (y != u);
	}
}
void dfs(int u, int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	st[u] = 1;
	for (int i = 1; i < 15; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 0; i < a[u].size(); i++)
		if (a[u][i] != father)
			if(!st[a[u][i]])dfs(a[u][i], u);
}
int lca(int u, int v)
{
	if (dep[u] < dep[v])swap(u, v);
	for (int i = 14; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v)return u;  ////////////////////////////////////////////////////////////
	for (int i = 14; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
int tmp[64];
void print(int res)
{
	if (res == 0) { puts("0"); return; }
	if (res < 0) { putchar('-'); res = 0 - res; }
	while (res) tmp[++tmp[0]] = res & 1, res >>= 1;
	while (*tmp) putchar(tmp[(*tmp)--] + '0');
	putchar('\n');
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
		if (!check[a][b])///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{
			add(a, b), add(b, a);
			check[b][a] = check[a][b] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i, -1);
	cin >> tot;
	for (int i = 0; i < idx; i++)
		if (is_bridge[i])
			a[id[e[i]]].push_back(id[e[i ^ 1]]);
	dfs(1,0);
	while (tot--)
	{
		int a, b,ans;
		cin >> a >> b;
		ans = dep[id[a]] + dep[id[b]] - 2 * dep[lca(id[a], id[b])] + 1;
		print(ans);
	}

	return 0;
}