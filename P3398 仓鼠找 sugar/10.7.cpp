

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10,K = 20;
int n, q;
int h[N], e[M], ne[M], idx;
int dep[N], fa[N][K];
bool st[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dfs(int u, int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	st[u] = true;
	for (int i = 1; i < K; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!st[j] && j != father)
			dfs(j, u);
	}
}

int lca(int u, int v)
{
	if (dep[u] < dep[v])swap(u, v);
	for (int i = K - 1; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v)return v;
	for (int i = K - 1; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

int main()
{
	cin >> n >> q;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1, 0);
	while (q--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = lca(a, b);
		int y = lca(c, d);
		int dist1 = dep[x] + dep[c] - 2 * dep[lca(x, c)];
		int dist2 = dep[x] + dep[d] - 2 * dep[lca(x, d)];
		int dist3 = dep[c] + dep[d] - 2 * dep[y];
		if (dist1 + dist2 == dist3)
		{
			cout << "Y" << endl;
			continue;
		}
		dist1 = dep[y] + dep[a] - 2 * dep[lca(y, a)];
		dist2 = dep[y] + dep[b] - 2 * dep[lca(y, b)];
		dist3 = dep[a] + dep[b] - 2 * dep[x];
		if (dist1 + dist2 == dist3)
		{
			cout << "Y" << endl;
			continue;
		}
		cout << "N" << endl;
	}

	return 0;
}